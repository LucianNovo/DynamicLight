#include <Adafruit_NeoPixel.h>

#define PIN 8

int fadelvl[]={255, 255, 255, 255, 255, 255, 255, 255, 252, 247, 235, 235, 230, 225, 218, 213, 208, 206, 199, 189, 187, 182, 182, 177, 175, 168, 165, 163, 158, 148, 146, 144, 144, 141, 139, 136, 134, 127, 122, 120, 117, 115, 112, 112, 110, 110, 108, 103, 96, 96, 93, 91, 88, 88, 88, 88, 84, 79, 76, 74, 74, 72, 72, 72, 72, 69, 69, 62, 60, 60, 57, 57, 57, 55, 55, 55, 55, 48, 48, 45, 45, 43, 43, 40, 40, 40, 40, 36, 36, 36, 33, 33, 31, 31, 31, 28, 28, 26, 26, 26, 26, 24, 24, 21, 21, 21, 21, 20, 19, 19, 16, 16, 16, 16, 14, 14, 14, 16, 12, 12, 12, 12, 12, 9, 9, 9, 9, 9, 9, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 12, 12, 14, 14, 16, 16, 16, 16, 21, 21, 21, 21, 24, 24, 26, 28, 28, 28, 31, 36, 33, 36, 36, 40, 40, 43, 43, 45, 48, 52, 55, 55, 55, 57, 62, 62, 64, 67, 72, 74, 79, 81, 86, 86, 86, 88, 93, 96, 98, 100, 112, 115, 117, 124, 127, 129, 129, 136, 141, 144, 148, 160, 165, 170, 175, 184, 189, 194, 199, 208, 213, 220, 237, 244, 252, 255, 255, 255, 255, 255, 255, 255};
boolean repeat = true;
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  Serial.begin(9600);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
//    gradient();
    breathIn();
//  // Some example procedures showing how to display to the pixels:
//  colorWipe(strip.Color(255, 0, 0), 50); // Red
//  colorWipe(strip.Color(0, 255, 0), 50); // Green
//  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//  // Send a theater pixel chase in...
//  theaterChase(strip.Color(127, 127, 127), 50); // White
//  theaterChase(strip.Color(127,   0,   0), 50); // Red
//  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
//
//  rainbow(20);
//  rainbowCycle(20);
//  theaterChaseRainbow(50);
}

void gradient(){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i,strip.Color(i*10, i*10, i*10));
  }
  strip.show();
}


// simple set value transition
void breathIn(){
  int i;
  while(repeat == true){
    for (i = 0; i < 299; i = i + 1) {
        for(int j=0; j<strip.numPixels(); j++){
          strip.setPixelColor(j,strip.Color(fadelvl[i],fadelvl[i],fadelvl[i]));
        }
        Serial.println(fadelvl[i]);
        strip.show();
        delay (20);
    }
  }  
}

//

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

