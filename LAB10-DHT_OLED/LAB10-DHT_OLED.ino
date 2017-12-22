#include <DHT.h>
#include <Wire.h>
#include <ESP_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_RESET  -1
ESP_SSD1306 display(OLED_RESET);

#define DHTTYPE DHT11
#define DHTPIN  15

DHT dht(DHTPIN, DHTTYPE, 15);

void setup() {
  Serial.begin(115200);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  if (isnan(humid) || isnan(temp)) {
    Serial.println("Fail to read from DHT sensor!");
  }
  else {
    display.setCursor(0, 0);
    display.println("Temp : " + String(temp, 2) + " C");
    display.println("Humid : " + String(humid, 2) + " %");
    display.drawRect(13,50,101,10,WHITE);
    display.fillRect(13,50,int(humid),10,WHITE);
    display.display();
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" , Humid: ");
    Serial.println(humid);
    delay(1000);
    display.clearDisplay();

  }
}
