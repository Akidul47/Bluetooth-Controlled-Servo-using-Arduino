#include <Servo.h>            
#include <SoftwareSerial.h>
int servopin=5;
SoftwareSerial jack(10,11);  //you can give any name without jack 
String str;
char c;
Servo akidul;               //you can give any name without akdiul
void setup(){
  jack.begin(9600);
  akidul.attach(servopin);
  Serial.begin(9600);
  pinMode(servopin,OUTPUT); 
  akidul.write(10);         //for the safety of servo it is good to set the servo angle 10
                   
}

void loop(){
  while(jack.available()>0)
  {
    c=jack.read();
    str +=c;
    Serial.println(str);
    delay(300);  
  }
  if(str=="ON"){
   akdiul.write(170);     //you can set the angle value of ON status as you want
   delay(3000);
  }
  else if(str=="OFF"){
  akdiul.write(15);       //you can set the angle value of ON status as you want
  delay(3000);
  }
 str="";                   
}


