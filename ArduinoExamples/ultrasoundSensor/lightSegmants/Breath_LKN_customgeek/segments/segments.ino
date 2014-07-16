/*
Light transitioner made by

Modified Sleep_LED made by Jeremy Saglimbeni 2011 thecustomgeek.com
inspired by Apple

Redesigned in California by Lucian Novosel
*/

#include <Adafruit_NeoPixel.h>


int i = 0;
//int delayScale = 2;
int LED_pin = 13;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, LED_pin, NEO_GRB + NEO_KHZ800);

void setup() { // bring the LED up nicely from being off
  pinMode(8, OUTPUT);//11 is output pin
  Serial.begin(9600);
  strip.show();
  for(i = 0 ; i <= 15; i+=1)
  {
    for(int j = 0; j<strip.numPixels(); j++){
      strip.setPixelColor(j,strip.Color(i, i, i));
    }
    Serial.println(i);
    strip.show();
    delay( 5);
  }
}

void loop(){
  
  //a few programs
  calmProgram();  //makes very slow, random transitions
  heifyProgram(); //makes very consistent fast transitions

  //Simulates a breath-in
  breathIn(1);
  breathIn(1);
  breathIn(1);
  breathIn(1);
  
  //Simulates a breath-out
  breathOut(1);
  breathOut(1);
  breathOut(1);
  
}

void calmProgram(){
  int repeat = 2;
  while(repeat > 0){
    breath(2);
    repeat--;
  }
}

void heifyProgram(){
  int repeat = 3;
  while(repeat > 0){
    breath(1);
    repeat--;
  }
}

void breath(int delayScale)
{
   breathIn(delayScale);
   breathOut(delayScale);
}

void breathIn(int delayScale){
  for(i = 15 ; i <= 255; i+=1)
  { 
    for(int j = 0; j<strip.numPixels(); j++){
      strip.setPixelColor(j,strip.Color(i, i, i));
    }
    Serial.println(i);
    strip.show();
    if (i > 150) {
      delay( delayScale * 4);
    }
    if ((i > 125) && (i < 151)) {
      delay( delayScale * 5);
    }
    if (( i > 100) && (i < 126)) {
      delay( delayScale * 7);
    }
    if (( i > 75) && (i < 101)) {
      delay( delayScale * 10);
    }
    if (( i > 50) && (i < 76)) {
      delay( delayScale * 14);
    }
    if (( i > 25) && (i < 51)) {
      delay( delayScale * 18);
    }
    if (( i > 1) && (i < 26)) {
      delay( delayScale * 19);
    }
  }
}

void breathOut(int delayScale){
  for(i = 255; i >=15; i-=1)
  {
    for(int j = 0; j<strip.numPixels(); j++){
      strip.setPixelColor(j,strip.Color(i, i, i));
    }
    Serial.println(i);
    strip.show();
    if (i > 150) {
      delay( delayScale * 4);
    }
    if ((i > 125) && (i < 151)) {
      delay( delayScale * 5);
    }
    if (( i > 100) && (i < 126)) {
      delay( delayScale * 7);
    }
    if (( i > 75) && (i < 101)) {
      delay( delayScale * 10);
    }
    if (( i > 50) && (i < 76)) {
      delay( delayScale * 14);
    }
    if (( i > 25) && (i < 51)) {
      delay( delayScale * 18);
    }
    if (( i > 1) && (i < 26)) {
      delay( delayScale * 19);
    }
  }
  delay( delayScale * 970);
}
