#include <Servo.h>
Servo Mike;
int ButtonPin = 8;
int State = 0;
int ButtonState;
long LastDebounceTime = 0;
long DebounceDelay = 50;
int LastButtonState = LOW;


void setup() {
  Mike.attach(6);
  pinMode(ButtonPin, INPUT);
  Mike.write(0);
}

void loop() {

  int Reading = digitalRead(ButtonPin);

  if (Reading != LastButtonState) {
    LastDebounceTime = millis();
  }

  if ((millis() - LastDebounceTime) > DebounceDelay) {

    if (Reading != ButtonState) {
      ButtonState = Reading;

      if (ButtonState == HIGH) {
        State = State + 1;
      }
    }
  }
  if (State > 4) {
    State = 0;
  }

  switch (State) {
    case 1:
      Mike.write(90);
      break;

    case 2:
      Mike.write(180);
      break;

    case 3:
      Mike.write(90);
      break;

    case 4:
      Mike.write(0);
      break;
  }

  LastButtonState = Reading;

}
