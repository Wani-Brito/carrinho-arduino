#include <Servo.h>
#include <stdio.h>

Servo meuServo;

#define In1 7
#define In2  6
#define In3  5
#define In4  4

int led1 = 2;
int led2 = 3;
int piscaAlerta1 = 9;  
int setaDireita = 12; 
int setaEsquerda = 13; 
int buzzer = A5;
 
#define ENA  10
#define ENB  11

int ldrPin = A0;
int ldrThreshold = 300;

void setup() {
 Serial.begin(9600);

 pinMode(In1, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(In2, OUTPUT);
 pinMode(In3, OUTPUT);
 pinMode(In4, OUTPUT);
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);

 pinMode(piscaAlerta1, OUTPUT);
 pinMode(setaDireita, OUTPUT);
 pinMode(setaEsquerda, OUTPUT);

 analogWrite(ENA,110);
 analogWrite(ENB,110);

 meuServo.attach(9);
 meuServo.write(0);
}
char cha;

  void loop() {

    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  if(Serial.available() > 0){
     cha = Serial.read();
     delay(1000);

     Serial.print(cha);
  
  if(cha == 'f'){
    digitalWrite(ENA, HIGH);
    digitalWrite(ENB, HIGH);

    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW);
    
      }
    if(cha == 'C'){
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,HIGH);
    digitalWrite(In4,LOW);

    digitalWrite(setaDireita, HIGH);
    delay(1000);
    digitalWrite(setaDireita, LOW);
    delay(1000);

      }
    if(cha == 'D'){
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);
    digitalWrite(setaEsquerda, HIGH);
    delay(1000);
    digitalWrite(setaEsquerda, LOW);
    delay(1000);

    
      }

  if(cha == 'B'){
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
    digitalWrite(In3,LOW);
    digitalWrite(In4,HIGH);

     }

  int ldrValue = analogRead(ldrPin);

  if(ldrValue < ldrThreshold){
    

    
    }
  if(cha == '0'){
    digitalWrite(In1,LOW); 
    digitalWrite(In2,LOW); 
    digitalWrite(In3,LOW); 
    digitalWrite(In4,LOW);  
                }
  
  if(cha == 'A'){
    
    digitalWrite(piscaAlerta1,HIGH);
    delay(500);
    digitalWrite(piscaAlerta1,LOW);
    delay(500);
    } 
                 
  if(cha == 'a'){
    digitalWrite(led1,HIGH); 
    digitalWrite(led2,HIGH);
   
                } 
              
  if(cha == 'W'){
    meuServo.write(90);
    delay(500);
    meuServo.write(0);
    delay(100); 
  }

  if(cha == 'H'){
    meuServo.write(0);
  //   delay(100); 
   }  

  if(ldrValue < ldrThreshold){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  }
}