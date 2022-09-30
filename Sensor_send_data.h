#include<SoftwareSerial.h>
SoftwareSerial SUART(13, 32); //SRX=DPin-4, STX=DPin-5
byte o;
byte list[32];


int send_data()
{
  
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
    int PMS1 = list[4]*256+list[5];
    int PMS2 = list[6]*256+list[7];
    int PMS3 = list[8]*256+list[9];

    int PME1 = list[10]*256+list[11];
    int PME2= list[12]*256+list[13];
    int PME3 = list[14]*256+list[15];

    Serial.println(PME1);
   return PME1;
  }
