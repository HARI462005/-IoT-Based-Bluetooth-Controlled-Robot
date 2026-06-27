#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

char cmd;

// Left Motor Driver
int IN1 = 27;
int IN2 = 26;
int IN3 = 25;
int IN4 = 33;

// Right Motor Driver
int IN5 = 14;
int IN6 = 12;
int IN7 = 13;
int IN8 = 15;

void setup() {

Serial.begin(9600);
SerialBT.begin("ESP32_RC_CAR");   // Bluetooth Name

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(IN5,OUTPUT);
pinMode(IN6,OUTPUT);
pinMode(IN7,OUTPUT);
pinMode(IN8,OUTPUT);

stopCar();
}

void stopCar(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);

digitalWrite(IN5,LOW);
digitalWrite(IN6,LOW);
digitalWrite(IN7,LOW);
digitalWrite(IN8,LOW);
}

void loop() {

if (SerialBT.available()){
cmd = SerialBT.read();
}

// Forward
if(cmd=='F'){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);

digitalWrite(IN5,HIGH);
digitalWrite(IN6,LOW);
digitalWrite(IN7,HIGH);
digitalWrite(IN8,LOW);
}

// Backward
else if(cmd=='B'){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

digitalWrite(IN5,LOW);
digitalWrite(IN6,HIGH);
digitalWrite(IN7,LOW);
digitalWrite(IN8,HIGH);
}

// Left
else if(cmd=='R'){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

digitalWrite(IN5,HIGH);
digitalWrite(IN6,LOW);
digitalWrite(IN7,HIGH);
digitalWrite(IN8,LOW);
}

// Right
else if(cmd=='L'){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);

digitalWrite(IN5,LOW);
digitalWrite(IN6,HIGH);
digitalWrite(IN7,LOW);
digitalWrite(IN8,HIGH);
}

// Stop
else if(cmd=='S'){
stopCar();
}

}