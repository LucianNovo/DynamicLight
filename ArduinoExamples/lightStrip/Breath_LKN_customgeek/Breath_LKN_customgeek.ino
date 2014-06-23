/*
Modified Sleep_LED made by Jeremy Saglimbeni 2011 thecustomgeek.com
but originally pioneered by Apple


Redesigned in California by Lucian Novosel
*/

#include <Adafruit_NeoPixel.h>


int i = 0;
int LED_pin;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, LED_pin, NEO_GRB + NEO_KHZ800);

void setup() { // bring the LED up nicely from being off
  Serial.begin(9600);
  strip.show();
  for(i = 0 ; i <= 15; i+=1)
  {
    strip.setPixelColor(i,strip.Color(i, i, i));
    Serial.println(i);
    strip.show();
//    analogWrite(LED_pin, i);
    delay(5);
  }
}

void loop()
{
  for(i = 15 ; i <= 255; i+=1)
  { 
    strip.setPixelColor(i,strip.Color(i, i, i));
    Serial.println(i);
    strip.show();
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  for(i = 255; i >=15; i-=1)
  {
    strip.setPixelColor(i,strip.Color(i, i, i));
    Serial.println(i);
    strip.show();
    if (i > 150) {
      delay(4);
    }
    if ((i > 125) && (i < 151)) {
      delay(5);
    }
    if (( i > 100) && (i < 126)) {
      delay(7);
    }
    if (( i > 75) && (i < 101)) {
      delay(10);
    }
    if (( i > 50) && (i < 76)) {
      delay(14);
    }
    if (( i > 25) && (i < 51)) {
      delay(18);
    }
    if (( i > 1) && (i < 26)) {
      delay(19);
    }
  }
  delay(970);
}

