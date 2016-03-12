#include "speakjetLib.h"
#include <SoftwareSerial.h>
SoftwareSerial speakjet = SoftwareSerial(0, speakjet_data_in);


//#define speakjet_rst 6
//#define speakjet_rdy 5
//#define speakjet_spk 4
//#define speakjet_bhf 3

const char * sentence1[] = { _hello, _world };
const char * sentence2[] = { _i, _am, _the, _speakjet};
const char * sentence3[] = { _a, _red, _light, _brightly, _shine, _s};


void setup() {
  Serial.begin(9600);
  speakjet.begin(9600);
  
  
  pinMode(speakjet_rst, OUTPUT);
  
  pinMode(speakjet_bhf, INPUT);
  pinMode(speakjet_rdy, INPUT);
  pinMode(speakjet_spk, INPUT);
 
  resetSpeakJet(speakjet_rst);
 
 
  Serial.print('i');
  Serial.print('\t');
  Serial.print("msg[i]");
  Serial.print('\t');
  Serial.print("rdy");
  Serial.print('\t');
  Serial.print("spk");
  Serial.print('\t');
  Serial.println("bhf");
 
}



void loop() {
 
  sendSentence(sentence1, P5);
  delay(10000);
  sendSentence(sentence2, P5);
  delay(10000);
  sendSentence(sentence3, P5);
  delay(10000);

}

void sendSentence(const char ** sentence, char pause) {
  int numWords = sizeof(sentence) / sizeof(sentence[0]);
  for(int w = 0; w < numWords ; w++) {
    for(int i = 0;i<strlen(sentence[w]); i++) {
      // wait for ready signal
      int rdy = digitalRead(!speakjet_rdy);
      while(!rdy) {
        rdy = digitalRead(!speakjet_rdy);
    
      Serial.print(i);
      Serial.print('\t');
      Serial.print(sentence[w][i]);
      Serial.print('\t');
      Serial.print(digitalRead(speakjet_rdy));
      Serial.print('\t');
      Serial.print(digitalRead(speakjet_spk));
      Serial.print('\t');
      Serial.println(digitalRead(speakjet_bhf)); 
      }
      //tran
      speakjet.print(sentence[w][i]);
      Serial.print(i);
      Serial.print('\t');
      Serial.print(sentence[w][i]);
      Serial.print('\t');
      Serial.print(digitalRead(speakjet_rdy));
      Serial.print('\t');
      Serial.print(digitalRead(speakjet_spk));
      Serial.print('\t');
      Serial.println(digitalRead(speakjet_bhf)); 
    }
    speakjet.print(pause);
  }
}

void resetSpeakJet(int speakjet_rst_pin){
 digitalWrite(speakjet_rst_pin, LOW);
 delay(100);
 digitalWrite(speakjet_rst_pin, HIGH);
}
