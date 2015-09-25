#include <Servo.h>

Servo botservo;  // create servo object to control a servo
Servo topservo;

int pos = 0;    // variable to store the servo position
byte i;
byte j;

void setup() {
  botservo.attach(5);  // attaches the servo on pin 9 to the servo object
  topservo.attach(3);
  Serial.begin(9600);
  topservo.write(180);
  botservo.write(0);
}

void loop() {
  // topservo.write(180);
  // botservo.write(0);

  for(i = 160; i >=130; i-=2) {
    topservo.write(i);
    delay(20);
    if(i%4 == 0) {
      for(j=12; j < 72; j+=4) {
        int sensorValue = analogRead(A0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V) then to distance:
        float voltage = sensorValue * (5.0 / 1023.0);
        float distance = 281.6588-438.174*voltage+306.2413*pow(voltage,2)-98.3268*pow(voltage,3)+11.6707*pow(voltage,4);
        Serial.print(j);
        Serial.print(",");
        Serial.print(i);
        Serial.print(",");
        Serial.println(distance);

        botservo.write(j);
        delay(100);
      }
    }
    else {
      for(j=72; j > 12; j-=4) {
        int sensorValue = analogRead(A0); // Read IR sensor (which goes from 0 - 1023) convert to a voltage (0 - 5V) then to distance:
        float voltage = sensorValue * (5.0 / 1023.0);
        float distance = 281.6588-438.174*voltage+306.2413*pow(voltage,2)-98.3268*pow(voltage,3)+11.6707*pow(voltage,4);
        Serial.print(j);
        Serial.print(",");
        Serial.print(i);
        Serial.print(",");
        Serial.println(distance);

        botservo.write(j);
        delay(100);
      }
    }
  }
}


