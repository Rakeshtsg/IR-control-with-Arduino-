#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define led1 4 //Associates led1 al to pin 4
#define led2 5 //Associates led2 al to pin 5
#define led3 6 //Associates led3 al to pin 6

void setup(){
  irrecv.enableIRIn();
  
  pinMode(led1, OUTPUT);    //Establishes led1 as an output
  pinMode(led2, OUTPUT);    //Establishes led2 as an output
  pinMode(led3, OUTPUT);    //Establishes led3 as an output
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFD08F7: //Change here for the HEX value of your button
          digitalWrite(led1, HIGH);
          delay(2000);
          digitalWrite(led1, LOW);
          }

        switch(results.value){
          case 0xFD8877: //Change here for the HEX value of your button
          digitalWrite(led2, HIGH);
          delay(2000);
          digitalWrite(led2, LOW);
          }

        switch(results.value){
          case 0xFD48B7: //Change here for the HEX value of your button
          digitalWrite(led3, HIGH);
          delay(2000);
          digitalWrite(led3, LOW);
          }


        irrecv.resume(); 
    }
}
