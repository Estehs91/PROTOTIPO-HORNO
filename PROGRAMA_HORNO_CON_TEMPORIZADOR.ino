#include <sensorntc.h>

#include <Displays.h>

int estado,sensor, potenciometro;

void setup() {
  // put your setup code here, to run once:
displays.init(8,9,10,11,12,13);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
sensorntc.initntc(1);

}

void loop() {
  // put your main code here, to run repeatedly:

  potenciometro=(analogRead(0)*99.0)/1023.0;
  sensor=sensorntc.leontc();

  estado=digitalRead(7);
  
  displays.cargarDato(sensorntc.leontc());
  
  if(estado==HIGH){
  if(sensor<potenciometro-1.0){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  }
  if(sensor>potenciometro+1.0){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  }
delay(500);
}
       else{
                    digitalWrite(2,LOW);
                    digitalWrite(3,LOW);
                    digitalWrite(4,LOW);
                    digitalWrite(5,LOW);
                    digitalWrite(6,LOW); 
       }
       
}
