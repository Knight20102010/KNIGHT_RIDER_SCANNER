#include <Adafruit_NeoPixel.h>

// Nastavenie výstupného pinu a počtu pixelov
#define PIN A5  //pin A5 sa nachadza na rovnakej linii ako napajanie a uzemnenie oznacene ako A5
#define NUM_PIXELS 8  // pocet pixelov - svetielok

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Inicializuje LED pás
  clearStrip(); // Zhasne všetky LED
}

void loop() {
  knightRider(3, 100, 4, 0xFF0000); // Cycles, Speed, Width, RGB Color (červená = 0xFF0000) K.I.T.T. - Speed znížené na 50
  //knightRider(3, 50, 4, 0xCCCC00); // Cycles, Speed, Width, RGB Color (žltá) K.A.R.R.
}

// Funkcia pre Knight Rider efekt
void knightRider(uint16_t cycles, uint16_t speed, uint8_t width, uint32_t color) {
  for (int i = 0; i < cycles; i++) {
    // Pohyb doprava
    for (int pos = 0; pos < NUM_PIXELS; pos++) {
      clearStrip();
      for (int trail = 0; trail < width; trail++) {
        if (pos - trail >= 0) {
          strip.setPixelColor(pos - trail, dimColor(color, trail + 1)); // Postupné stmievanie
        }
      }
      strip.show();
      delay(speed);
    }

    // Pohyb doľava
    for (int pos = NUM_PIXELS - 1; pos >= 0; pos--) {
      clearStrip();
      for (int trail = 0; trail < width; trail++) {
        if (pos + trail < NUM_PIXELS) {
          strip.setPixelColor(pos + trail, dimColor(color, trail + 1)); // Postupné stmievanie
        }
      }
      strip.show();
      delay(speed);
    }
  }
}

// Funkcia na zhasnutie všetkých LED
void clearStrip() {
  for (int i = 0; i < NUM_PIXELS; i++) {
    strip.setPixelColor(i, 0); // Nastaví LED na vypnutie
  }
  strip.show();
}

// Funkcia na stmievanie farby
uint32_t dimColor(uint32_t color, uint8_t factor) {
  uint8_t r = (color >> 16) & 0xFF;
  uint8_t g = (color >> 8) & 0xFF;
  uint8_t b = color & 0xFF;

  r = r / factor;
  g = g / factor;
  b = b / factor;

  return strip.Color(r, g, b);
}
