#include <Adafruit_NeoPixel.h>
#ifdef AVR
#include <avr/power.h>
#endif

#define NUMPIXELS        24
#define PIN_NEOPIXEL     12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

int Shock = 3;
int val; 

void setup() {
  Serial.begin(115200);
  
  pinMode(Shock, INPUT);

#if defined(NEOPIXEL_POWER)
  // If this board has a power control pin, we must set it to output and high
  // in order to enable the NeoPixels. We put this in an #if defined so it can
  // be reused for other boards without compilation errors
  pinMode(NEOPIXEL_POWER, OUTPUT);
  digitalWrite(NEOPIXEL_POWER, HIGH);
#endif

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(50); // not so bright
}

// the loop routine runs over and over again forever:
void loop() {
  val = digitalRead(Shock); // read and assign the value of digital interface 3 to val
  if(val == HIGH) // when sensor detects a signal, the LED flashes
  {
    Serial.println("Detectado");
        pixels.fill(0x7F00FF);
    pixels.show();
      delay(200);

      pixels.fill(0x000000);
      pixels.show();
      delay(200);
  }
  else
  {
    pixels.fill(0x000000);
      pixels.show();
      delay(200);
  }
}
