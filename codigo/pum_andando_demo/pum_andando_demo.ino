int sensorPin = A0; // define sensor pin
int threshold = 800; // set threshold value


void setup() {
  Serial.begin(9600); // initialize serial communication

}

void loop() {
int sensorValue = analogRead(sensorPin); // read sensor value
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    // do something when shock is detected
    Serial.println("Shock detected!");
    delay(100); // wait for a second to avoid multiple detection
  }

  delay(10); // delay between readings
}
