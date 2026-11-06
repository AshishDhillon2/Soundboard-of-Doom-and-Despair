#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "neotrellis.h"

const int SDA = 20; //I2C0 SDA, p. 541
const int SCL = 21; //I2C0 SCL, p. 541

void init_i2c() {
  i2c_init(i2c0, 100000);

  gpio_set_function(SDA, GPIO_FUNC_I2C);
  gpio_set_function(SCL, GPIO_FUNC_I2C);

  // 12.2.1.3, p. 893
  gpio_pull_up(SDA);
  gpio_pull_up(SCL);
  gpio_set_slew_rate(SDA, GPIO_SLEW_RATE_SLOW);
  gpio_set_slew_rate(SCL, GPIO_SLEW_RATE_SLOW);
  gpio_set_input_hysteresis_enabled(SDA, true);
  gpio_set_input_hysteresis_enabled(SCL, true);
}
// NeoTrellis with Interrupt Example

/*
#include "Adafruit_NeoTrellis.h"

Adafruit_NeoTrellis trellis;

#define INT_PIN 10

// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return trellis.pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return trellis.pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return trellis.pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//define a callback for key presses
void blink(keyEvent evt){
  
  if(evt.bit.EDGE == SEESAW_KEYPAD_EDGE_RISING)
    trellis.pixels.setPixelColor(evt.bit.NUM, Wheel(map(evt.bit.NUM, 0, trellis.pixels.numPixels(), 0, 255))); //on rising
  else if(evt.bit.EDGE == SEESAW_KEYPAD_EDGE_FALLING)
    trellis.pixels.setPixelColor(evt.bit.NUM, 0); //off falling
    
  trellis.pixels.show();
}

void setup() {
  Serial.begin(9600);
  //while(!Serial);

  pinMode(INT_PIN, INPUT);
  
  if(!trellis.begin()){
    Serial.println("could not start trellis");
    while(1) delay(1);
  }
  else{
    Serial.println("trellis started");
  }

  //activate all keys and set callbacks
  for(int i=0; i<NEO_TRELLIS_NUM_KEYS; i++){
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_RISING);
    trellis.activateKey(i, SEESAW_KEYPAD_EDGE_FALLING);
    trellis.registerCallback(i, blink);
  }

  //do a little animation to show we're on
  for(uint16_t i=0; i<trellis.pixels.numPixels(); i++) {
    trellis.pixels.setPixelColor(i, Wheel(map(i, 0, trellis.pixels.numPixels(), 0, 255)));
    trellis.pixels.show();
    delay(50);
  }
  for(uint16_t i=0; i<trellis.pixels.numPixels(); i++) {
    trellis.pixels.setPixelColor(i, 0x000000);
    trellis.pixels.show();
    delay(50);
  }
}

void loop() {
  if(!digitalRead(INT_PIN)){
    trellis.read(false);
  }
  delay(2);
}
*/