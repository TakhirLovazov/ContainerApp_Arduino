#include<Servo.h>
Servo serv;
int pos = 0;
const int ECHO_PIN=13;
const int TRIG_PIN=12;

void setup() {
 serv.attach(11);
 pinMode(ECHO_PIN,INPUT);
 pinMode(TRIG_PIN,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(20); 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const long duration = pulseIn(ECHO_PIN,HIGH);
  int distance = duration/29/2;
  if(duration==0){
   Serial.println("113");
   } 
  else{
    if (distance<10)
    {
      Serial.println("10");
      serv.attach(11);
      serv.write(20);
      //delay(100);
      //serv.detach();
    }
    else
    {
//      Serial.print("distance:");
      serv.attach(11);
      Serial.println(distance);
      serv.write(90);
      //delay(100);
      //serv.detach();
      //Serial.println(" cm");
    }
     
  }
 delay(1000);
}
