/*
  Simple blink program. 
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  Open Sourcery. Anyone and everyone can get a piece. 
*/
 
int led = 1; // establishing the pin
int milliseconds = 1000; // length of the pulse

// initiates after reset is pressed
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
 
}
 
// toggles the light on and off for milliseconds long
void loop() {
    digitalWrite(led, HIGH); 
    delay(milliseconds);
    digitalWrite(led, LOW);
    delay(milliseconds);
}
    
