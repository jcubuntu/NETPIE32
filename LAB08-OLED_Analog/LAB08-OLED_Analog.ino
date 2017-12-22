#include <ESP_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>

#define OLED_RESET  -1

ESP_SSD1306 display(OLED_RESET);

void setup() {
  pinMode(34,INPUT); 
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE); 
}

void loop() {
  int value,percentValue;
  value = analogRead(34);
  percentValue = map(value,0,4096,0,100);
  display.setCursor(0, 0);
  display.println("Display analog value");
  display.print("Value : ");
  display.println(value);
  display.print("Percent : ");
  display.print(percentValue);
  display.print(" %");
  display.drawRect(13,50,101,10,WHITE);
  display.fillRect(13,50,percentValue,10,WHITE);
  display.display(); 
  display.clearDisplay();
}
