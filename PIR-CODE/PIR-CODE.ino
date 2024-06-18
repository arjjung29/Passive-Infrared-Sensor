//int sensor = 14; for Node MCU
int sensor = 2; //For Arduino UNO 
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(sensor);   
  delay(100);  
  if (val == HIGH){
    Serial.println("MOTION DETECTED !");
    delay(700);
  }  

}
