#include "wordCmds.h"
#include <SoftwareSerial.h>

SoftwareSerial speakjet = SoftwareSerial(0, 2);

#define button1 11
#define button2 12
#define button3 13

#define speakjet_rst 6
#define speakjet_rdy 5
#define speakjet_spk 4
#define speakjet_bhf 3

const char * sentence1[] = { _hello, _world };
const char * sentence2[] = { _i, _am, _the, _speakjet};
const char * sentence3[] = { _a, _red, _light, _brightly, _shine, (char *) &_s[1]};


void setup() {
  Serial.begin(9600);
  speakjet.begin(9600);
  

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
  
  pinMode(speakjet_rst, OUTPUT);
  
  pinMode(speakjet_bhf, INPUT);
  pinMode(speakjet_rdy, INPUT);
  pinMode(speakjet_spk, INPUT);
 
 digitalWrite(speakjet_rst, LOW);
 delay(100);
 digitalWrite(speakjet_rst, HIGH);
 
 
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
  delay(4000);
  sendSentence(sentence2, P5);
  delay(4000);
  sendSentence(sentence3, P5);
  delay(4000);
 // for(int w = 0; w < 2; w++) {
  //for(int i = 0;i<strlen(sentence1[w]); i++) {
    /*
    if(sentence1[w][i] == 0){
      Serial.println("END WORD\n");
      break;
    }*/
    /*
    speakjet.print(sentence1[w][i]);
    Serial.print(i);
    Serial.print('\t');
    Serial.print(sentence1[w][i]);
    Serial.print('\t');
    Serial.print(digitalRead(speakjet_rdy));
    Serial.print('\t');
    Serial.print(digitalRead(speakjet_spk));
    Serial.print('\t');
    Serial.println(digitalRead(speakjet_bhf)); 
    */
    
    
 // }
 // }

  
}

void sendSentence(const char ** sentence, char pause) {
  
  int numWords = sizeof(sentence) / sizeof(sentence[0]);
  for(int w = 0; w < numWords ; w++) {
    for(int i = 0;i<strlen(sentence1[w]); i++) {
      // wait for ready signal
      while(digitalRead(!speakjet_rdy));
      //tran
      speakjet.print(sentence1[w][i]);
      Serial.print(i);
      Serial.print('\t');
      Serial.print(sentence1[w][i]);
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
