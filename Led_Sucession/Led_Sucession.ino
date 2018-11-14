int Led1 = 6;
int Led2 = 5;
int Led3 = 4;
int ButtonPin = 8;
int State = 0;
int ButtonState;
long LastDebounceTime = 0;
long DebounceDelay = 50;
int LastButtonState = LOW;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(ButtonPin, INPUT);
}

void loop() {

  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);

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
  if (State > 3) {
    State = 0;
  }

  switch (State) {
    case 1:
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, LOW);
      break;

    case 2:
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, HIGH);
      digitalWrite(Led3, LOW);
      break;

    case 3:
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      digitalWrite(Led3, HIGH);
      break;
  }

  LastButtonState = Reading;
  
}
