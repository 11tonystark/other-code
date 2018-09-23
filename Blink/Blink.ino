void setup()
{
  pinMode(13, OUTPUT);          // sets the digital pin 13 as output
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(10, OUTPUT);  

}

void loop()
{
//CLOCKWISE
digitalWrite(13, LOW);       // sets the digital pin 13 on
  //delay(10);                  // waits for a second
  digitalWrite(11, LOW);        // sets the digital pin 13 off
  delay(1);
  
  digitalWrite(13, HIGH);       // sets the digital pin 13 on
  //delay(10);                  // waits for a second
  digitalWrite(11, LOW);        // sets the digital pin 13 off
  delay(1);     


//ANTI CLOCKWISE
digitalWrite(13, LOW);       // sets the digital pin 13 on
  //delay(10);                  // waits for a second
  digitalWrite(11, LOW);        // sets the digital pin 13 off
  delay(1);
  
  digitalWrite(13, HIGH);       // sets the digital pin 13 on
  //delay(10);                  // waits for a second
  digitalWrite(11, HIGH);        // sets the digital pin 13 off
  delay(1);     
  
  
  
  
 
  
  
  // waits for a second
}
