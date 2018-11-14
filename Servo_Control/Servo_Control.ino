#include <Servo.h>
Servo Mike;
long userInput;

void setup() {
  Mike.attach(6);
  Serial.begin(9600);
  Serial.println("Enter number for control option");
  Serial.println("1. Bring servo to 0 degree position.");
  Serial.println("2. Turn servo to 90 degree position.");
  Serial.println("3. Turn servo to 180 degree position.");
  Serial.println("4. Run steps 1 to 3");
  Serial.println();

}

void loop() {
  Mike.write(90);
  //while (Serial.available()) {
  userInput = Serial.read();
  if (userInput <= '180')
  {
    Mike.write(0);
    delay(500);
    Mike.write(userInput);
    delay(800);
    Mike.write(0);
  }
}
//    Mike.write(0);
//    delay(2000);
//    Mike.write(90);
//    delay(2000);
//    Mike.write(180);
//    delay(2000);

