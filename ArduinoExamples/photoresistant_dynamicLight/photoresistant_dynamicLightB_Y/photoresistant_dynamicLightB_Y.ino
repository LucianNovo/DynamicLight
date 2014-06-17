/*

  RGB_LED_Color_Fade_Cycle.pde
  
  Cycles through the colors of a RGB LED

*/

// LED leads connected to PWM pins
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 10;
const int RED_LED_PIN = 11;

//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int ledPin = 11;   //the pin the LED is connected to
                  //we are controlling brightness so 
                  //we use one of the PWM (pulse width
                  // modulation pins)

void setup() {
  pinMode(ledPin, OUTPUT); //sets the LED common to varying intensities depending on the photoresistor
}

void loop() {
  
 int lightLevel = analogRead(lightPin); //Read the
                                        // lightlevel
  
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
         //adjust the value 0 to 900 to
         //span 0 to 255
         
 lightLevel = constrain(lightLevel, 0, 255);//make sure the 
                                           //value is betwween 
                                           //0 and 255
                                           
  analogWrite(ledPin, lightLevel);  //write the value

}


