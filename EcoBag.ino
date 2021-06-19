//Written by Oluwafemi Oreoluwa 
//2 Libraries Used | 2 Redundant
// Originally Written in 2019   |  Latest Commit in June 2021

/*
You're looking at an Arduino Program written for ATMEGA Micro-controllers. It reads temperature & Humidity Data
and writes it temporaryly in the memory of the Atmega 329pu microntroller.
Thereafter, the data is displayed  on a (16x2)LCD.

The Code starts with a Welcome Text "Epic Flow" for exactly 2000miliseconds
Next, Temperature is displayed in degree celcius
And Humidity is displyaed in Percentage

*/




#include <LiquidCrystal.h> // Library for the LCD 
#include "DHT.h"  // Library for the DHT-22/11 sensor
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 1       // data pin for the Sensor is set for PIN 1 on the Microcontroller or Arduino Development Board
#define DHTTYPE DHT11  // dht sensor type is specified here. Because there are several types of dht sensors in this case were using dht11

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // all the LCD pins are being assigned to a particular pin on the Arduino board
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup() {
dht.begin();   // the Dht sensor is initialized here with dht.begin()
lcd.begin(16, 2);
lcd.setCursor(3,0);
lcd.print("Epic Flow");
delay(2000);
lcd.clear();
controllerpowerstate(); 
sensor_t sensor;
dht.temperature().getSensor(&sensor); 
dht.humidity().getSensor(&sensor);

//Welcome Screen Displays "Epic Flow"

}

void loop() {
sensors_event_t event;
dht.temperature().getEvent(&event);
lcd.setCursor(1,0);
lcd.print(F("Temp: "));
lcd.setCursor(8,0);
lcd.print(event.temperature);
// dht.temperature fetches the temperature data
// lcd.print(event.temperature) prints the data on the lcd

}


 
int controllerpowerstate(){
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  delay(1000);

//
}

int chargingalert(){
  while(1){
  lcd.setCursor(6,0);
  lcd.print("Low Power");
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Low Power");
  }

  // this functions is meant to display ("lower power on the lcd when the circuit power is insufficient")
}