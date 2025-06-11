int sensorPin = A0; // Analog pin for sensor input
int motoPin = 8;
void setup() {
  pinMode(motoPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  digitalWrite(motoPin, LOW);
  while (!Serial) ;
  Serial.println("Input 1 to move motor");
}

void loop() {
  int sensorValue1 = analogRead(sensorPin); // Read sensor value (0-1023)
  delay(100);
  int sensorValue2 = analogRead(sensorPin);
  delay(100);
  int sensorValue3 = analogRead(sensorPin);
  
  int avgReading = (sensorValue1 + sensorValue2 + sensorValue3) / 3;
  // Serial.println(avgReading); // Send the value to the Serial Plotter

  if (avgReading > 540) {
    Serial.println("Starting Pump");
    runPump();
  }
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state==1){
      digitalWrite(motoPin, HIGH);
      // Serial.println("Starting Pump");
      
    }
    else if (state==2) {
      digitalWrite(motoPin, LOW);
    }
  }

  delay(43200000); // Delay for readability (adjust as needed)  
}

void runPump() {
  digitalWrite(motoPin, HIGH);
  delay(150000);
  digitalWrite(motoPin, LOW);
}
