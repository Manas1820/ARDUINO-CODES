//pins for the two IR sensors
int sensor_1=2;
int sensor_2=4;
// Pin for the bulb
int bulb=9;
// count is to get the number of people inside it
int count= 0;

void setup() 
{                
  pinMode(sensor_1,INPUT);    //Pin  is connected to the output of sensor  
  pinMode(sensor_2,INPUT);    //Pin  is connected to the output of sensor
  pinMode(bulb,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  //Serial.print(digitalRead(sensor_1));
  //Serial.print(digitalRead(sensor_2));
  if(digitalRead(sensor_1)==HIGH)      
  {
    count ++;
    Serial.print(count);              // Displays the current no of people in the room  
    brightness(count);
    delay(1000);
  }
  if(digitalRead(sensor_2)==HIGH)
  {
    count --;
    Serial.print(count);              // Displays the current no of people in the room  
    brightness(count);
    delay(1000);
  }
}

void brightness(int count)          // Control the brightness of the bulb according to the number of people in the room
{
 analogWrite(bulb,51*count);
}             
