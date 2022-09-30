
// Motor A

//in2
int motor1Pin1 = 2; 
//in1
int motor1Pin2 = 12; 


//Motor B

//in4
int motor1Pin3 = 14; 
//in3
int motor1Pin4 = 15; 



void stop_car(){
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW); 
  delay(1000);
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
