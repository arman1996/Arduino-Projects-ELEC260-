int Pot = A1;
int MotorInput = 9;
int Speed;
int Motor;
//        int Volts;

void setup() {
  Serial.begin(9600);
  pinMode(Pot, INPUT);
  pinMode(Motor, OUTPUT);
  

}

void loop() {
  Motor = analogRead(Pot);
  Serial.println(Motor);
  Speed = map(Motor,0, 1023, 0, 255);
  //Serial.println(Speed);
  //Volts = map(Motor, 0, 1023, 0.00, 5.00);
  //Serial.println(Volts);
  analogWrite(MotorInput, Speed);
}
