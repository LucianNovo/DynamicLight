#DynamicLight
============

###Hi! 
This repository catalogues a few circuits I made with Arduino. In the summer of 2014 I was drafted to help with an interactive sculpture for visualizing energy use. I created a motion sensing script that uses a Sharpe infrared sensor to detect body heat, and a series of lighting programs to give the sculpture life.


[![Breathing Light](https://raw.githubusercontent.com/LucianNovo/DynamicLight/master/ArduinoExamples/lightStrip/progress/customGeek.gif "Breathing Light")](https://www.youtube.com/watch?v=YoK2YnTQCqk)

[![Motion Sensor](https://raw.githubusercontent.com/LucianNovo/DynamicLight/master/ArduinoExamples/IR_sensor/progress/IRsensor.gif "Motion Sensor")](https://www.youtube.com/watch?v=hVRZTDxuRS8)


At the same time I applied for a job at the CLTC, and wanted to show-off my prototyping chops. 

##Color transitioning
A common problem in lighting is comfort and versatility. In general, humans prefer blue light in the day and orange light at night. To provide for this dynamic without creating two luminares- I programmed a LED to subtly transition between blue and orange.

[![Color Transitioning](https://raw.githubusercontent.com/LucianNovo/DynamicLight/master/ArduinoExamples/lightTransitioner_uno/progress/lightTransitioner.gif "Color Transitioning")](https://www.youtube.com/watch?v=CvsXu49ZDVk)


##Ambient Compensation
Another focus in lighting is consistency. Lights shouldn't suddenly turn on- or add a binary difference of light to the room. Like temperature, there is an optimal level of light to live under. I wrote a script which would accommodate for the ambient light and adjust the intensity of a LED responsively. Using a photoresistor, this circuit maintains a specific level of luminance. 


[![Ambient Compensation](https://raw.githubusercontent.com/LucianNovo/DynamicLight/master/ArduinoExamples/photoresistance_uno/photoresistanceUnoCode/photoresistance_uno/photoresistance_uno.gif "Ambient Compensation")](https://www.youtube.com/watch?v=V8dHYTta7nA)

##Combining Powers
Thinking of how synonymous these problems were, I created a hybrid program. The circuit would compensate for the lack of light to a certain intensity, then transition to an orange light. The circuit could maintain optimal lighting in a naturally lit room throughout cloud conditions. Past the time of sunset, the light would transition to orange. 
