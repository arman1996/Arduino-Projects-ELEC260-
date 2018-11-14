int Pot = A1;
float Volts;

void setup() {
  Serial.begin(9600);
  pinMode(Pot, INPUT);
}

void loop() {

  //Volts = map(analogRead(Pot), 0.00, 1023.00, 0.00, 5.00);
  Volts = (analogRead(Pot) * 4.9) / 1000;

  Serial.println(analogRead(Pot));
  Serial.println(Volts);
  delay(200);
}

