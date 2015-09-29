#include <Servo.h>

Servo botservo;  // create servo object to control a servo
Servo topservo;

byte i; // variables to store position of each servo
byte j;

void setup() {
  botservo.attach(5);   // attaches servos to respective pins
  topservo.attach(3);
  Serial.begin(9600);   // open serial connection
  topservo.write(180);  // reset position of servos
  botservo.write(0);
  delay(1000);
}

void loop() {
  for(i = 92; i >= 70; i-=1) { // sweep top servo
    topservo.write(i); // move servo to next position
    delay(100);

    if(i%2 == 0) { // alternate direction of pan servo sweept servo
      for(j=40; j <= 96; j+=1) {
        int sensorValue = analogRead(A0); // Convert IR sensor to distance:
        float voltage = sensorValue * (5.0 / 1023.0);
        term0 = 281.6588
        term1 = -438.174*voltage
        term2 = 306.2413*pow(voltage,2)
        term3 = -98.3268*pow(voltage,3)
        term4 = 11.6707*pow(voltage,4)
        float distance = term0+term1+term2+term3+term4;
        Serial.print(j); //print out data on servo positions and ir distance
        Serial.print(",");
        Serial.print(i);
        Serial.print(",");
        Serial.println(distance);

        botservo.write(j); // move servo to next position
        delay(100);
      }
    }
    else {
      for(j=96; j >= 40; j-=1) {
        int sensorValue = analogRead(A0); // Convert IR sensor to distance:
        float voltage = sensorValue * (5.0 / 1023.0);
        term0 = 281.6588
        term1 = -438.174*voltage
        term2 = 306.2413*pow(voltage,2)
        term3 = -98.3268*pow(voltage,3)
        term4 = 11.6707*pow(voltage,4)
        float distance = term0+term1+term2+term3+term4;

        Serial.print(j); //print out data on servo positions and ir distance
        Serial.print(",");
        Serial.print(i);
        Serial.print(",");
        Serial.println(distance);

        botservo.write(j); //move servo to next position
        delay(100);
      }
    }
  }
}