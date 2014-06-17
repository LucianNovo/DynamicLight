/*

  RGB_LED_Color_Fade_Cycle.pde
  
  Cycles through the colors of a RGB LED

*/

// LED leads connected to PWM pins
const int RED_LED_PIN = 8;
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 10;
const int COMMON_LED_PIN = 11;

int lightPin = 0; //the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)

// Used to store the current intensity level of the individual LEDs
int redIntensity = 0;
int greenIntensity = 0;
int blueIntensity = 0;
int commonIntensity = 1;

// Length of time we spend showing each color
const int DISPLAY_TIME = 10; // In milliseconds


void setup() {
//  pinMode(COMMON_LED_PIN, OUTPUT); //sets the LED common to varying intensities depending on the photoresistor
}

void loop() {
//     analogWrite(BLUE_LED_PIN, blueIntensity);
//     analogWrite(GREEN_LED_PIN, greenIntensity);
//     analogWrite(RED_LED_PIN, redIntensity);
//   int lightLevel = analogRead(lightPin); //Read the
//                                          // lightlevel
//    
//   lightLevel = map(lightLevel, 0, 900, 0, 255); 
//           //adjust the value 0 to 900 to
//           //span 0 to 255
//           
//   lightLevel = constrain(lightLevel, 0, 255);//make sure the 
//                                             //value is betwween 
//                                             //0 and 255
//                                             
//    analogWrite(COMMON_LED_PIN, 100);  //write the value
    for(blueIntensity = 255; blueIntensity >= 0; blueIntensity-=1){
      analogWrite(BLUE_LED_PIN, blueIntensity);
      delay(DISPLAY_TIME);
    }
    for(blueIntensity = 0; blueIntensity <= 255; blueIntensity+=1){
      analogWrite(BLUE_LED_PIN,blueIntensity);
      delay(DISPLAY_TIME);
    }
    for(redIntensity = 255,greenIntensity = 255; redIntensity >= 0 && greenIntensity >= 0; greenIntensity-=1,redIntensity-=1){
      analogWrite(GREEN_LED_PIN,greenIntensity);
      analogWrite(RED_LED_PIN,redIntensity);
      delay(DISPLAY_TIME);
    }
    for(redIntensity = 0,greenIntensity = 0; redIntensity <= 255 && greenIntensity <= 255; greenIntensity+=1,redIntensity+=1){
      analogWrite(GREEN_LED_PIN,greenIntensity);
      analogWrite(RED_LED_PIN,redIntensity);
      delay(DISPLAY_TIME);
    }
}


