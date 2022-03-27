#define MOISTURE_SENSOR 36
#define NB_MESURE 3

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("Start calibrage");
  
  int calibrage = avg_mesure(MOISTURE_SENSOR);

  Serial.printf("Calibrage finish\n Value: %i\n", calibrage);
  delay(500);
}

int avg_mesure(int sensor_pin) {
  int total_mesure;
  int avg_mesure;

  digitalWrite(sensor_pin, HIGH);  // Sets the sensor to on 
  delay(500); 
  
  for (int i=0; i < NB_MESURE; i++) {
    
    int value = analogRead(sensor_pin);
    total_mesure += value;
    delay(500);
  }

  digitalWrite(sensor_pin, LOW); // Sets the sensor to off
  avg_mesure = total_mesure / NB_MESURE;

  return avg_mesure;
}