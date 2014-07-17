void setup() {
  pinMode (2,OUTPUT);//attach pin 2 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  
  
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
digitalWrite(2, HIGH);
//  long duration, inches, cm;
  long duration[6], inches[6], cm[6];

  //array of pins to write to.
  int echoPins[6] = { 4, 6, 8, 10};
  int trigPins[6] = { 3, 5, 7, 9};


  for(int i = 1; i < 7; i++){
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(trigPins[i], OUTPUT);// attach pin 3 to Trig
    digitalWrite(trigPins[i], LOW);
    delayMicroseconds(2);
    digitalWrite(trigPins[i], LOW);
    delayMicroseconds(5);
    digitalWrite(trigPins[i], LOW);
  
    // The same pin is used to read the signal from the PING))): a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode (echoPins[i], INPUT);//attach pin 4 to Echo
    duration[i-1] = pulseIn(echoPins[i] , HIGH);
  
    // convert the time into a distance
    inches[i-1] = microsecondsToInches(duration[i-1]);
    cm[i-1] = microsecondsToCentimeters(duration[i-1]);
   
    Serial.print(inches[i-1]);
    Serial.print("in, ");
    Serial.print(cm[i-1]);
    Serial.print("cm");
    Serial.println();
    
    //delay the sensor reads
    delay(10);
  }
 
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
