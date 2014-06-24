/*
Mac-style light transitions proposed Disqus contributor ecosmurf
inspired by Appple

Redesigned in California by Lucian Novosel
*/

#include <Adafruit_NeoPixel.h>
#define PIN 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

int fadelvl[]={255, 255, 255, 255, 255, 255, 255, 255, 252, 247, 235, 235, 230, 225, 218, 213, 208, 206, 199, 189, 187, 182, 182, 177, 175, 168, 165, 163, 158, 148, 146, 144, 144, 141, 139, 136, 134, 127, 122, 120, 117, 115, 112, 112, 110, 110, 108, 103, 96, 96, 93, 91, 88, 88, 88, 88, 84, 79, 76, 74, 74, 72, 72, 72, 72, 69, 69, 62, 60, 60, 57, 57, 57, 55, 55, 55, 55, 48, 48, 45, 45, 43, 43, 40, 40, 40, 40, 36, 36, 36, 33, 33, 31, 31, 31, 28, 28, 26, 26, 26, 26, 24, 24, 21, 21, 21, 21, 20, 19, 19, 16, 16, 16, 16, 14, 14, 14, 16, 12, 12, 12, 12, 12, 9, 9, 9, 9, 9, 9, 7, 7, 7, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 9, 9, 9, 12, 12, 12, 14, 14, 16, 16, 16, 16, 21, 21, 21, 21, 24, 24, 26, 28, 28, 28, 31, 36, 33, 36, 36, 40, 40, 43, 43, 45, 48, 52, 55, 55, 55, 57, 62, 62, 64, 67, 72, 74, 79, 81, 86, 86, 86, 88, 93, 96, 98, 100, 112, 115, 117, 124, 127, 129, 129, 136, 141, 144, 148, 160, 165, 170, 175, 184, 189, 194, 199, 208, 213, 220, 237, 244, 252, 255, 255, 255, 255, 255, 255, 255};
int repeat = 8;

void setup() {
  strip.show();
  pinMode(8, OUTPUT);//11 is output pin
  Serial.begin(9600);
}

void loop(){
  int i;
  while(repeat > 0){
    for (i = 0; i < 299; i = i + 1) {
      //sets the color from the array.
      for(int j = 0; j<strip.numPixels(); j++){
        strip.setPixelColor(j,strip.Color(fadelvl[i], fadelvl[i], fadelvl[i]));
      }

      //standard logging
      Serial.println("The intensity level.");
      Serial.println(fadelvl[i]);

      //this makes the entire effect choppy
      strip.show();
      delay (20);
    }
    
  repeat--; //decrement the amount of repitions
  }
}
