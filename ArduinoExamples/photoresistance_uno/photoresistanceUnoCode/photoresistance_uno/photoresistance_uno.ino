/*
 * A simple programme that will change the intensity of
 * an LED based  * on the amount of light incident on 
 * the photo resistor.
 * 
 */
/*
 * A lighting system implemented by Lucian Novosel. 
 * Works with the LightingSchematic_v1 diagram described and visualized
 * in the fritzingDiagrams folder.
 */

//PhotoResistor Pin
int lightPin = 0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int ledPinR = 9;
int ledPinG = 10; 
int ledPinB = 11;   //the pin the LED is connected to
                  //we are controlling brightness so 
                  //we use one of the PWM (pulse width
                  // modulation pins)
void setup()
{
  pinMode(ledPinR, OUTPUT); //sets the led pin to output
  pinMode(ledPinG, OUTPUT); 
  pinMode(ledPinB, OUTPUT); 
}
 /*
 * loop() - this function will start after setup 
 * finishes and then repeat
 */
void loop()
{
 int lightLevel = analogRead(lightPin); //Read the
                                        // lightlevel
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
         //adjust the value 0 to 900 to
         //span 0 to 255



 lightLevel = constrain(lightLevel, 0, 255);//make sure the 
                                           //value is betwween 
                                           //0 and 255
 lightLevel = 255 - lightLevel;     //invert the illuminence character of the light - this line will make the light compensate for ambient light
 analogWrite(ledPinR, lightLevel);  //write the value
 analogWrite(ledPinG, lightLevel);  //write the value
 analogWrite(ledPinB, lightLevel);  //write the value
}
