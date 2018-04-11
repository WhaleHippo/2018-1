/* 

//analogWrite
#include "Arduino.h"

int i = 0;
void setup() {
  pinMode(13, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (digitalRead(13)==HIGH){
      i = 0;
  }
  else{
    i = ((i+1)%255);
  }
  
  analogWrite(10, i);
  delay(5);
  
}
//*/


//digitalWrite
#include "Arduino.h"

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH);
  
  delay(500);
  digitalWrite(10, LOW);

  delay(500);
}
//*/

/*
//interupt
#include "Arduino.h"
volatile int isrFlag = 0;

void pin2ISR(){
  isrFlag = !isrFlag;
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  attachInterrupt(0, pin2ISR, CHANGE);
}

void loop() {
  if(isrFlag == 1){
    digitalWrite(10, LOW);  
  }
  else{
    digitalWrite(10, HIGH);
  }
}
//*/
/*
//삼각함수를 이용한 파도타기
#include "Arduino.h"

void setup() {  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}
int i = 0;
void loop() {
  analogWrite(8, 128+128*sin(i/100 - 1.06));
  analogWrite(9, 128+128*sin(i/100));
  analogWrite(10, 128+128*sin(i/100 + 1.07));

  i++;
  delay(10);
}
*/
