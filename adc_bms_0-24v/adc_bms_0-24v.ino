int sensorPin = A0;    
int ledPin = 13;      
double sensorValue = 0;  
double val=0,val1=0;
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
  val = map(sensorValue,0,700,0,3.4);
   val1 = map(val,0,3.4,0,25);
 Serial.println(val); 
 
// Serial.println();
  Serial.print(val1,3);  
 // Serial.println();
  a=5;
// Serial.write(val);
  delay(300); 
  
 // digitalWrite(ledPin, HIGH);  
 
 // delay(sensorValue);          
        
 // digitalWrite(ledPin, LOW);   
  
  //delay(sensorValue);                  
}
