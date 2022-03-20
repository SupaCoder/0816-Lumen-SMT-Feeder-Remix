#include <Servo.h>

Servo feeder0;
Servo feeder1;
Servo feeder2;
Servo feeder3;
Servo feeder4;
Servo feeder5;
Servo feeder6;
Servo feeder7;
Servo feeder8;
Servo feeder9;
Servo feeder10;
Servo feeder11;

String inData;
void setup() {

  Serial.begin(115200);
  Serial.println("Feeduino");
  Serial.println("ok");

  feeder0.attach(2);
  feeder1.attach(3);
  feeder2.attach(4);
  feeder3.attach(5);
  feeder4.attach(6);
  feeder5.attach(7);
  feeder6.attach(8);
  feeder7.attach(9);
  feeder8.attach(10);
  feeder9.attach(11);
  feeder10.attach(12);
  feeder11.attach(13);
  
//setFeeder(0, 129);
//setFeeder(0, 90);
}

//Fx a
//F - Feeder
//x - number
//a - value

//Fx S
//Feeder 1 Serve

//Set Fx R<> P<>
//Set Feeder x Retract and Push

void loop() {
  while (Serial.available() > 0) {
    char recieved = Serial.read();
    inData += recieved;

    if (recieved == '\n') {
      processCommand(inData);
      inData = "";
    }
  }
}

void processCommand(String inData) {
  inData.trim();
  inData.toUpperCase();
  Serial.print("ok");
  if(inData.startsWith("F")){
    String temp = inData.substring(1);
    servePart(temp.toInt());
    Serial.print(": Served F");
    Serial.print(temp.toInt());
    
  }
  
  Serial.println("");
}

void servePart(int feeder) {
  setFeeder(feeder, 80);//88
  delay(200);
  setFeeder(feeder, 140);
  delay(200);
  setFeeder(feeder, 129);
}

void setFeeder(int feeder, int value) {
  switch (feeder) {
    case 0:
      feeder0.write(value);
      break;
    case 1:
      feeder1.write(value);
      break;
    case 2:
      feeder2.write(value);
      break;
    case 3:
      feeder3.write(value);
      break;
    case 4:
      feeder4.write(value);
      break;
    case 5:
      feeder5.write(value);
      break;
    case 6:
      feeder6.write(value);
      break;
    case 7:
      feeder7.write(value);
      break;
    case 8:
      feeder8.write(value);
      break;
    case 9:
      feeder9.write(value);
      break;
    case 10:
      feeder10.write(value);
      break;
    case 11:
      feeder11.write(value);
      break;
    default:
      break;
  }
}
