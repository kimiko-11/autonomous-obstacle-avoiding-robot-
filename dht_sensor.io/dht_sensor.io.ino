#include "DHT.h"

#define DPIN 4        // Pin to connect DHT sensor (GPIO number) D2
#define DTYPE DHT11   // Define DHT 11 or DHT22 sensor type

DHT dht(DPIN, DTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  
  // Reading temperature and humidity
  float tc = dht.readTemperature(false);  // Temperature in Celsius
  float tf = dht.readTemperature(true);   // Temperature in Fahrenheit
  float hu = dht.readHumidity();          // Humidity in percentage
  
  // Print the data in a format recognized by the Serial Plotter
  Serial.print("Temp_C:"); 
  Serial.print(tc);  // Temperature in Celsius
  Serial.print("\t");  // Tab separator
  Serial.print("Temp_F:"); 
  Serial.print(tf);   // Temperature in Fahrenheit
  Serial.print("\t");
  Serial.print("Humidity:"); 
  Serial.println(hu);  // Humidity percentage
  
  // This format allows the Serial Plotter to plot different variables
}

