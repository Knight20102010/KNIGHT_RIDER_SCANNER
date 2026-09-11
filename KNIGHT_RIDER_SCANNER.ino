#include <Adafruit_NeoPixel.h>

#define LED_PIN   A5
#define LED_COUNT 8
//drawKnightRider(i, 255, 255, 0);

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.show();
}

void drawKnightRider(int pos, int r, int g, int b)
{
  strip.clear();

  // hlavné svetlo
  strip.setPixelColor(pos, strip.Color(r, g, b));

  // dosvit vľavo
  if (pos > 0)
    strip.setPixelColor(pos - 1, strip.Color(r / 4, g / 4, b / 4));

  // dosvit vpravo
  if (pos < LED_COUNT - 1)
    strip.setPixelColor(pos + 1, strip.Color(r / 4, g / 4, b / 4));

  strip.show();
}

void loop()
{
  // ČERVENÝ Knight Rider

  for (int i = 0; i < LED_COUNT; i++) {
    drawKnightRider(i, 255, 0, 0);
    delay(100);
  }

  for (int i = LED_COUNT - 2; i > 0; i--) {
    drawKnightRider(i, 255, 0, 0);
    delay(100);
  }
}