#include <SoftwareSerial.h>

//int sensor = 14; for Node MCU
int sensor = 2; //For Arduino UNO 
int val = 0;

SoftwareSerial GSM(7, 6); // SoftwareSerial(rxPin, txPin, inverse_logic), creating object for sending AT Commands to GSM Module

void setup() {
  
  Serial.begin(9600);
  GSM.begin(9600);
  pinMode(sensor,INPUT);

}

void loop() {
  
val = digitalRead(sensor);   
  delay(100);  
  if (val == HIGH){
    Serial.println("MOTION DETECTED !");
    Serial.println("Calling.....");
    callup();
    delay(700);
  }  

}

void update(){
  delay(500);
  while (Serial.available()) 
  {
    GSM.write(Serial.read()); //Forward what Serial received to Software Serial Port
  }
  while(GSM.available()) 
  {
    Serial.write(GSM.read()); //Forward what Software Serial received to Serial Port
  }
}

void callup(){
  Serial.println("Initializing..."); 
  delay(1000);

  GSM.println("AT"); // If initialization is success GSM Module will return "OK"
  update();
  GSM.println("ATD+ +916369727213;"); //  phone number to dial
  update();
  delay(20000); // wait for 20 seconds...
  GSM.println("ATH"); //hang up the call
  update();
}

