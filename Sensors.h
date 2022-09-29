#include <DFRobot_SGP40.h>
#include <Wire.h>
DFRobot_SGP40   mySgp40(&Wire);



// Motor A
//in2
int motor1Pin1 = 14; 
//in1
int motor1Pin2 = 12; 
//Motor B
//in4
int motor1Pin3 = 33; 
//in3
int motor1Pin4 = 32; 

#include<SoftwareSerial.h>
SoftwareSerial SUART(2, 0); //SRX=DPin-4, STX=DPin-5
byte o;
byte list[32];
String PMS1;
#include <WiFi.h>
#include <PubSubClient.h>
#define BUILTIN_LED 2
#define MSG_BUFFER_SIZE 20
const char* ssid = "ITEK 2nd";
const char* password = "Four_Sprints_F21v";
const char* mqtt_server = "test.mosquitto.org";

String missionCmd[100];
int missionCmdIndex=0;

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg =0;
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi (){
    delay(10);
    Serial.println();
    Serial.print("Connected to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password);

    while (WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    
    }

    randomSeed(micros());

    Serial.println("");
    
    Serial.println("Wifi connected");
    
    Serial.println("IP address: ");
    
    Serial.println(WiFi.localIP());
}

char getCommandFromMessage(String message){
   return message.charAt(0);
} 
int getValueFromMessage(String message){
  String valueString = message.substring(1); //creates a new string starting from index 1 (after the command letter)
  int value = valueString.toInt(); //converts a string to an integer
  return value;
}

 //******************************************
 //** PUBSUB MQTT CLIENT callback FUNCTION **
 //******************************************
 void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
 
  String temp=""; // string to store command
  missionCmdIndex = 0; // variable to count number of commands
  for (int i = 0; i < length; i++) {
 
  if ((char)payload[i]=='s'){ //stop
  Serial.println("");
  Serial.println("Mission data received");
 
  //** PRINT OUT MISSION DATA (HERE, INSTEAD, YOU WANT TO CALL A FUNCTION THAT RUNS THE MISSION)
 for (int i = 0;i<missionCmdIndex;i++){

 Serial.print("Command: ");
 Serial.print(getCommandFromMessage(missionCmd[i]));
 Serial.print(" ");
 Serial.print("Parameter: ");
 Serial.println(getValueFromMessage(missionCmd[i]));
 }
 }
 temp += (char)payload[i]; // add character to mission command

 if ((char)payload[i]==' ') // if we receive next mission command
 {
 missionCmd[missionCmdIndex++]=temp; // store command and increment qeue index
 temp = ""; // clear temp string
 }

 }

}
void send_data(){
  if (SUART.available()){
    o = SUART.read();
    if (o == 66) {
      list[0] = o;
     int tot = 66;
      for (int i = 1; i < 32; i++){
        while (!SUART.available());
        byte g = SUART.read();
        list[i] = g;
        if (i!=31){
        tot += g;
        }
        }
      }
    }
    PMS1 = list[4]*256+list[5];
    int PMS2 = list[6]*256+list[7];
    int PMS3 = list[8]*256+list[9];

    int PME1 = list[10]*256+list[11];
    int PME2= list[12]*256+list[13];
    int PME3 = list[14]*256+list[15];

    
}

void reconnect(){
    while (!client.connected()){
        
    Serial.println("Attempting MQTT connection...");

    String clientId = "ESP8266Client-";

    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())){
        
    Serial.println("connected");

    client.publish("outTopic", "Hellow frind");
    } else {
    Serial.println("failed, rc=");
    Serial.println(client.state());
    Serial.println("Try again in 5 sec...");
    delay(5000);
    }

    }
}

void stop_car(){
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  }


void forward(int seconds){
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW); 
  delay(seconds*1000);
  stop_car();
}

  void backward(int seconds){
    // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
  delay(seconds*1000);
  stop_car();
    }

    void right(int seconds){
      Serial.println("Moving left");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
      delay(seconds*1000);
  stop_car();

      }

      void left(int seconds){
         Serial.println("Moving right");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
  delay(seconds*1000);
  stop_car();
        }


void setup(){
    pinMode(BUILTIN_LED, OUTPUT);
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server,1883);
    Serial.begin(115200);
    SUART.begin(9600);

    Wire.setPins(13,15);

    Wire.begin();

    Serial.begin(115200);
    Serial.println("SGP40 is starting");

    while(mySgp40.begin(/* duration = */10000) !=true){
        Serial.println("failed to init chip, check if the chip connection is fine");
        delay(1000);
    }
    Serial.println("-----------------");
    Serial.println("sgp40 init success");
    Serial.println("-----------------");





      // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);


  Serial.begin(115200);

  delay(250);
}
