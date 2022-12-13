#include "WiFi.h"
#include "server.h"
int trigPin = 5; 
int echoPin = 4;
int photoPin = A0;
int led = 2;
void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(photoPin, INPUT); 
  pinMode(led,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  WiFi_init(true);
  server_init();
} 
 struct Str{
   int dist;
   int ph;
 };
void loop() { 
  Str buf;
  server.handleClient();
  int duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = duration / 58;
  if(fl){
    if(distance<20){
      digitalWrite(led, LOW); 
    }else{
      digitalWrite(led, HIGH); 
    }
  }else{
    if(analogRead(photoPin) < 30){
      digitalWrite(led, LOW); 
    }else{
      digitalWrite(led, HIGH); 
    }
  }
  
  buf.dist = distance;
  buf.ph = analogRead(photoPin);
  Serial.write((byte*)&buf, sizeof(buf));
  // Serial.println(" ");

  // Serial.println();

  // Serial.println(); 
  delay(100);
}

