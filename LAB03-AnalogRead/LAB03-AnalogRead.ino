int value = 0;

void setup() {
  Serial.begin(115200);
  pinMode(34,INPUT);
}

void loop() {
  value = analogRead(34);
  Serial.print("analog value = ");
  Serial.println(value);
  delay(500);
}
