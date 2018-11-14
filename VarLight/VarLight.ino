int Led = 3;
int Brightness;
int Pot = A2;
int Light;


void setup() {

  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Pot, INPUT);
  

}

void loop() {

  Brightness = analogRead(Pot);

  Light = map(Brightness, 0, 1023, 0, 255);

  analogWrite(Led, Light);
}
