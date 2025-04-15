#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// TFT display pin definition
#define TFT_DC  2
#define TFT_RST 4
#define TFT_CS  5

// TFT display configuration
#define TFT_WIDTH 280
#define TFT_HEIGHT 240
#define TFT_ROTATION 1
#define BRIGHTNESS_PIN 22

// Create display object
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  
  // Initialize display
  tft.init(TFT_HEIGHT, TFT_WIDTH);
  tft.setRotation(TFT_ROTATION);
  tft.fillScreen(ST77XX_BLACK);
  analogWrite(BRIGHTNESS_PIN, 100);
  
  // Print "Hello World" in center
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(3);
  
  int16_t x, y;
  uint16_t w, h;
  tft.getTextBounds("Hello World", 0, 0, &x, &y, &w, &h);
  
  tft.setCursor((TFT_WIDTH - w) / 2, (TFT_HEIGHT - h) / 2);
  tft.print("Hello World");
}

void loop() {
  // Nothing to do here
}