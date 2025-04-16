// test of tft_espi and the rest of project configuration

#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

const int lineHeight = 16;
const int maxLines = 50;
String lines[maxLines];
const int visibleLines = 240 / lineHeight;
int scrollSpeed = 5;

extern "C" void app_main(void) {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);

  sprite.createSprite(tft.width(), tft.height());
  sprite.setSwapBytes(true);
  sprite.setTextColor(TFT_GREEN, TFT_BLACK);

  for (int i = 0; i < maxLines; i++) {
    lines[i] = String(50 - i);
  }

  int yOffset = 0;
  int scrollPos = 0;

  while (true) {
    sprite.fillSprite(TFT_BLACK);

    yOffset -= scrollSpeed;
    if (yOffset <= -lineHeight) {
      yOffset += lineHeight;
      scrollPos = (scrollPos + 1) % maxLines;
    }

    for (int i = 0; i < visibleLines + 2; i++) {
      int lineIndex = (scrollPos + i) % maxLines;
      int yPosition = i * lineHeight + yOffset;
      
      if (yPosition > -lineHeight && yPosition < tft.height()) {
        String text = lines[lineIndex];
        int textWidth = sprite.textWidth(text);
        int xPosition = (tft.width() - textWidth) / 2;
        
        sprite.drawString(text, xPosition, yPosition);
      }
    }

    sprite.pushSprite(0, 0);
    vTaskDelay(pdMS_TO_TICKS((10 - scrollSpeed % 10) * 10));
  }
}