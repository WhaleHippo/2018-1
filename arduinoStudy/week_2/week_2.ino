/*
//1. digitalRead
#include "Arduino.h"
void setup(){
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
}
void loop(){
  if(digitalRead(11) == HIGH){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
  delay(100);
}
//*/

/*
//2. analogRead
#include "Arduino.h"
void setup(){
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}
void loop(){
  if(analogRead(A0) > 700){
    digitalWrite(13, LOW);
    Serial.println("Hello Arduino!");
  }
  else{
    digitalWrite(13, HIGH);
    Serial.println("NO Arduino!");
  }
  delay(1000);
}
//*/



//3. Serial Output
#include "Arduino.h"
void setup(){
  Serial.begin(115200);
}
void loop(){
  Serial.println("Hello Arduino!");
  delay(500);
}
//*/

/*
//4. analogRead + Serial Output
#include "Arduino.h"
void setup(){
  pinMode(A0, INPUT);
  Serial.begin(115200);
}
void loop(){
  int sensorValue = analogRead(A0);
  Serial.print("sensor ");
  Serial.println(sensorValue);
  delay(500);
}
//*/


/*
//5. Serial Input 1 NO parsing
#include "Arduino.h"
void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}
void loop(){
  while(Serial.available()){
    char a = Serial.read();
    if(a == 'u'){
      digitalWrite(13, HIGH);
      Serial.println("HIGH");
    }
    else{
      digitalWrite(13, LOW);  
      Serial.println("LOW");
    }
  }
}
//*/


/*
//6. interupt
#include "Arduino.h"
volatile int isrFlag = 0;

void pin2ISR(){
  isrFlag = !isrFlag;
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  Serial.begin(115200);
  attachInterrupt(0, pin2ISR, CHANGE); // pin 2
}

void loop() {
  if(isrFlag == 1){
    digitalWrite(10, LOW); 
    Serial.println("interrupt!");
    isrFlag = 0;
  }
  else{
    digitalWrite(10, HIGH);
  }
}
//*/

