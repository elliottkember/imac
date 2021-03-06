#define FIRMWARE_NAME "soulmate-example"
#define N_LEDS 64
#define LED_COLS 32
#define LED_ROWS 2
#define CYCLE_LENGTH_IN_MS 120000
#define FADE_DURATION 3000
#define SOULMATE_MILLIAMPS 700
// For debugging, if you want a slightly faster build:
// #define SKIP_BLUETOOTH true

#include <Soulmate.h>

void warm() {
  fill_solid(Soulmate.led_arr, N_LEDS, CRGB::Peru);
}

void white() {
  fill_solid(Soulmate.led_arr, N_LEDS, CRGB::White);
}

void red() {
  fill_solid(Soulmate.led_arr, N_LEDS, CRGB::Red);
}

void purple() {
  fill_solid(Soulmate.led_arr, N_LEDS, CRGB::Purple);
}

float rainbowHue = 0;
void rainbow() {
  rainbowHue += beatsin16Float(2, 0.01, 0.5);

  for (int y = 0; y < LED_ROWS; y++) {
    for (int x = 0; x < LED_COLS; x++) {
      int8_t index = gridIndexHorizontal(x, y);
      Soulmate.led_arr[index] = CHSV(rainbowHue + x + y * 180, 255, 255);
    }
  }
}

void rainbow2() {
  hue += beatsin16Float(2, 0.01, 0.5);

  for (int y = 0; y < LED_ROWS; y++) {
    for (int x = 0; x < LED_COLS; x++) {
      int8_t index = gridIndexHorizontal(x, y);
      Soulmate.led_arr[index] = CHSV(hue + x * 3, 255, 255);
    }
  }
}

void setup() {
  Soulmate.addRoutine("Warm white", warm);
  Soulmate.addRoutine("White", white);
  Soulmate.addRoutine("Red", red);
  Soulmate.addRoutine("Purple", purple);
  Soulmate.addRoutine("Rainbow", rainbow);
  Soulmate.addRoutine("Rainbow2", rainbow2);

  Soulmate.setup();
}

void loop() {
  Soulmate.loop();
}
