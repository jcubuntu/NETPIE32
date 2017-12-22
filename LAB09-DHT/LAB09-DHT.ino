#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 15

DHT dht(DHTPIN, DHTTYPE, 15);

void setup() {
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  if (isnan(humid) || isnan(temp)) {
    Serial.println("Fail to read from DHT sensor!");
  }
  else {
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" , Humid: ");
    Serial.println(humid);
    delay(1000);
  }
}
