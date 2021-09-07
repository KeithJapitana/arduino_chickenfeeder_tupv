#include <DS3231.h>

DS3231  rtc(SDA, SCL);
Time t;
#define R1 11
#define R2 10
#define R3 9
#define SolW 8
#define SolR 5
#define Solwater 12
#define Cleaner 7
/* 
 Time para mag bubod  
 */
const int onHour1= 6;
const int onMin1= 0;
const int OffHour1=6;
const int OffMin1 = 1;


const int onHour2= 9;
const int onMin2= 0;
const int OffHour2=9;
const int OffMin2 = 1;


const int onHour3= 12;
const int onMin3= 0;
const int OffHour3=12;
const int OffMin3 = 1;


const int onHour4= 15;
const int onMin4= 0;
const int OffHour4=15;
const int OffMin4 = 1;


const int onHour5= 18;
const int onMin5= 0;
const int OffHour5=18;
const int OffMin5 = 1;

//---------------------------------------------
int buttonState = 0; 
int CalD = 250;

// Solenoid Timing Cleaning
const int WonHour = 16;
const int WonMin = 0;
const int WOffHour = 16;
const int WOffMin = 5;



void setup() {
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(SolW,OUTPUT);
  pinMode(SolR,OUTPUT);
  pinMode(Cleaner,OUTPUT);
  pinMode(Solwater,INPUT);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(SolW, HIGH);
  digitalWrite(SolR, HIGH);
  Serial.begin(115200);
  rtc.begin();
  
}

void loop() {

  
  // Sensor Switch for Water
  buttonState = digitalRead(Solwater);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(SolR, LOW);
  } else {
    // turn LED off:
    digitalWrite(SolR, HIGH);
  }




  // Serial Monitoring  
  t = rtc.getTime();

  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  

  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  Serial.println(rtc.getTimeStr());
  
  delay(1000);



 // Feeding Timing Section
  //1st nga bubod
  if(t.hour == onHour1 && t.min ==onMin1)
  {
  //FORWARD
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R1, HIGH);
  delay(200);
  Serial.print("BUBORING ");
  //reverse 
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R1, HIGH);
  delay(60000);
  Serial.print("TAPOS NA BUBOD ");
  

  
  
  }
    else if (t.hour == OffHour1 && t.min == OffMin1)
    {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      Serial.print("SARADO NA ");
    }
    else {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      
      
    }




    
 //2nd na bubod
 if(t.hour == onHour2 && t.min ==onMin2){
   //FORWARD
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R1, HIGH);
  delay(200);
  Serial.print("BUBORING ");
  //reverse 
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R1, HIGH);
  delay(60000);
  Serial.print("TAPOS NA BUBOD ");
  
  }
    else if (t.hour == OffHour2 && t.min == OffMin2)
    {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      Serial.print("SARADO NA ");

     
    }
    else {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
     
    }





    
//3rd na bubod
if(t.hour == onHour3 && t.min ==onMin3){
    //FORWARD
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R1, HIGH);
  delay(200);
  Serial.print("BUBORING ");
  //reverse 
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R1, HIGH);
  delay(60000);
  Serial.print("TAPOS NA BUBOD ");
  }
    else if (t.hour == OffHour3 && t.min == OffMin3)
    {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      Serial.print("SARADO NA ");
     
    }
    else {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      
    }



    
    //4th na bubod
if(t.hour == onHour4 && t.min ==onMin4){
    //FORWARD
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R1, HIGH);
  delay(200);
  Serial.print("BUBORING ");
  //reverse 
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R1, HIGH);
  delay(60000);
  Serial.print("TAPOS NA BUBOD ");
  }
    else if (t.hour == OffHour4 && t.min == OffMin4)
    {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      Serial.print("SARADO NA ");

    }
    else {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
    }
    
    
    
    
    
    //5th nga bubod
  if(t.hour == onHour5 && t.min ==onMin5)
  {
  //FORWARD
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R1, HIGH);
  delay(200);
  Serial.print("BUBORING ");
  //reverse 
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(R1, LOW);
  delay(CalD);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R1, HIGH);
  delay(60000);
  Serial.print("TAPOS NA BUBOD ");
  

  
  
  }
    else if (t.hour == OffHour5 && t.min == OffMin5)
    {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      Serial.print("SARADO NA ");
    }
    else {
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R1, HIGH);
      
      
    }



    //Cleaning Timing Section ---------------------------------------
    if(t.hour == WonHour && t.min ==WonMin){
    digitalWrite(SolW,HIGH);
    digitalWrite(Cleaner,LOW);
    delay(210000);
    digitalWrite(SolW,LOW);
    digitalWrite(Cleaner,HIGH);
    delay(300000);
    Serial.println("Water CLEANING ON");
    
  }
    else if (t.hour == WOffHour && t.min == WOffMin)
    {
    digitalWrite(SolW,LOW);
    digitalWrite(Cleaner,HIGH);
    Serial.println("Water CLEANING OFF");
    }
    else {
     digitalWrite(SolW,LOW);
    digitalWrite(Cleaner,HIGH);
    
    }


}
