//Maanya Goenka
//CS 232
//01.28.2020
//birthday and noteDurations arrays were adapted from create.arduino.cc

#include "pitches.h" //adding the note library

int buzzerPin = 3;
int pushPin = 12;
int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;

int birthday[]=     //array of notes that are used for the birthday song
  {NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4, 0,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, 0,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4, 0,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5};
int durations[]={4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 
                 4, 4, 4, 8, 4, 4, 4, 4, 4, 4,
                 4, 8, 4, 4, 4, 4, 4, 4}; //durations of the corresponsing notes

void setup(){
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int stateOfButton = digitalRead(pushPin); //reading the digital input
  if(stateOfButton == 1){ 
    for(int i=0; i<28; i++){ 
      analogWrite(random(9,12), 255); //random lighting up of lEDs
      delay(75);
      analogWrite(random(9,12), 255);
      delay(75);
      analogWrite(random(9,12), 255);
      delay(75);
      analogWrite(ledPin1, 0);
      analogWrite(ledPin2, 0);
      analogWrite(ledPin3, 0);
      int noteDuration = 1000/durations[i]; //calculating the note duration by dividing a second by note type 
      tone(buzzerPin, birthday[i], noteDuration); 
      int pauseTime = noteDuration * 1.1;   //setting a pause time between notes
      delay(pauseTime);
      if(digitalRead(pushPin) == 0)
      break;
      Serial.println(stateOfButton);
    }
    delay(1000);
  }
  else{
    Serial.println(stateOfButton);
    noTone(buzzerPin);
    analogWrite(ledPin1, 0);
    analogWrite(ledPin2, 0);
    analogWrite(ledPin3, 0);
    stateOfButton = digitalRead(pushPin);
  } 
}
