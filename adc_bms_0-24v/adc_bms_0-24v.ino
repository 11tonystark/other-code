
int sensorPin = A0;    
int ledPin = 13;      
double sensorValue = 0;  
double val=0;
int a;

void setup() {
  
  Serial.begin(38400);
  
  pinMode(ledPin, OUTPUT);  
}

//Map function
 double map( double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void loop() {
 
  sensorValue = analogRead(sensorPin);  
  val = map(sensorValue,0,1023,0,24);
  
 Serial.println(val); 
 
 Serial.println();
  Serial.println(val,3);  
 // Serial.println();
  a=5;
// Serial.write(val);
  delay(100); 
  
 // digitalWrite(ledPin, HIGH);  
 
 // delay(sensorValue);          
        
 // digitalWrite(ledPin, LOW);   
  
  //delay(sensorValue);                  
}
