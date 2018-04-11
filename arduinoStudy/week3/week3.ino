
#include "Arduino.h"

#define MOTOR_PIN_H 3
#define MOTOR_PIN_L 5
#define MOTOR_PIN_EN 7

float s = 0.0;
float speed_increment  = 0.01;
float speed_threshold = 1.0;
void setMotorSpeed(float Speed){ // set Mortor Speed

  // speed : -1.0 ~ 1.0
  if(Speed < 0.0){
    analogWrite(MOTOR_PIN_L, -Speed * 255.0);
    digitalWrite(MOTOR_PIN_H, LOW);
  }
  else{
    analogWrite(MOTOR_PIN_H, Speed * 255.0);
    digitalWrite(MOTOR_PIN_L, LOW);
  }
}

void setup(){
  pinMode(MOTOR_PIN_H , OUTPUT);
  pinMode(MOTOR_PIN_L , OUTPUT);
  pinMode(MOTOR_PIN_EN, OUTPUT);
  digitalWrite(MOTOR_PIN_EN, HIGH);
}

void loop(){
  setMotorSpeed(s);
  s += speed_increment;
  if((s >= speed_threshold) || (s <= -speed_threshold)){
    speed_increment *= -1.0;
  }
  delay(10);
}
//*/
/*
#include "Arduino.h"
#include "Servo.h"
#define SERVO_PIN 7
Servo servo;

void setup(){
  pinMode(SERVO_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
}

void loop(){
  for(int i=0; i<180; i++){
    servo.write(i);
    delay(10);
  }
  for(int i=0; i<180; i++){
    servo.write(180-i);
    delay(10);
  }  
}

//*/

/*
#include "Arduino.h"
#include "Servo.h"
#define SERVO_PIN 3
Servo servo;
int angle = 0;

void setup(){
  Serial.begin(115200);
  servo.attach(SERVO_PIN);
}
void loop(){
  while(Serial.available()){
    char a = Serial.read();
    if(a == 'l'){
      servo.write(angle++);
      Serial.println(angle);
      delay(10);
    }
    else if(a == 'r'){
      servo.write(angle--);
      Serial.println(angle);
      delay(10);
    }
  }
}
//*/
