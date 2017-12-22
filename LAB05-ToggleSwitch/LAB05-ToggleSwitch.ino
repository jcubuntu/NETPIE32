#define SWPIN 0
#define LEDPIN 16

int ledState = 0;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(SWPIN, INPUT);
}
void loop() {
  int  reading = digitalRead(SWPIN);
  if (reading == 0) {
    delay(500);
    ledState = !ledState;
  }
  digitalWrite(LEDPIN, ledState);

}
