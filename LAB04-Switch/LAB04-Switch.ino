#define SWPIN 35
#define LEDPIN 16

void setup() {
  pinMode(LEDPIN, OUTPUT); // Set as output
  pinMode(SWPIN, INPUT);   // Set as input
}

void loop(){
  if (digitalRead(SWPIN) == HIGH){
    digitalWrite(LEDPIN,HIGH);
  }
  else{
    digitalWrite(LEDPIN,LOW);
  }
}
