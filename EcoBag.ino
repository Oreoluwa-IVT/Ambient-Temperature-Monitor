// Code For the Ecobag
// Libraries for this Can be download on the google drive link http://bit.ly/librariesToFly_Ore
// Written by Oluwafemi Oreoluwa December 25th 2020


#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT22 
#define DHTPIN 7  
DHT_Unified dht(DHTPIN, DHTTYPE);

LiquidCrystal seeme(1,2,3,4,5,6);
uint32_t delayMS;


void setup() {
  seeme.begin(16,2);
  Serial.begin(9600);
  dht.begin();
  
  Serial.println("Ecobag: Data Log");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  
  Serial.println("Temperature");
  Serial.println(F("°C"));
  Serial.println(F("°C"));
  Serial.println(F("°C"));


  dht.humidity().getSensor(&sensor);
  Serial.println("Humidity");
  Serial.println(F("%"));
  Serial.println(F("%"));
  Serial.println(F("%"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  
  delay(delayMS);
  sensors_event_t event;            // Get temperature event and print its value.
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error - No Temperature Reading"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
