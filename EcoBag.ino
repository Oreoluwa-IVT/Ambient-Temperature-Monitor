#include <LiquidCrystal.h>
#include "DHT.h"
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 1
#define DHTTYPE DHT11

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup() {
dht.begin();  
lcd.begin(16, 2);
lcd.setCursor(3,0);
lcd.print("Epic Flow");
delay(2000);
lcd.clear();
controllerpowerstate(); 
sensor_t sensor;
dht.temperature().getSensor(&sensor); 
dht.humidity().getSensor(&sensor);
  // initial Welcome text "Epic flow"

}

void loop() {
sensors_event_t event;
dht.temperature().getEvent(&event);
lcd.setCursor(1,0);
lcd.print(F("Temp: "));
lcd.setCursor(8,0);
lcd.print(event.temperature);

//okay
  
}


 
int controllerpowerstate(){
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  delay(1000);
}

int chargingalert(){
  while(1){
  lcd.setCursor(6,0);
  lcd.print("Low Power");
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Low Power");
  }
}
