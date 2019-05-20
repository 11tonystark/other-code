char received_data;   //variable to store read data
void setup() {
  Serial.begin(38400);
}

void loop() { 
  //if(Serial.available()>0)  //check for any data received
  { 
      received_data = Serial.read();  //read received data      
      Serial.print("received data is: ");
      Serial.print(received_data);  //display received data
  }
}
