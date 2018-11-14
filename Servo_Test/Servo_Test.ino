#include <Servo.h>
Servo Mike;
long userInput;


void setup() {
  Mike.attach(6);
  Serial.begin(9600);

}

void loop() {
  Mike.write(0);
  delay(2000);
  Mike.write(90);
  delay(2000);
  Mike.write(180);
  delay(2000);

}
