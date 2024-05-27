#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int AirValue = 500;   
const int WaterValue = 350;  
const int ThresholdValue = 395; //This is the threshold value UwU
int soilMoistureValue = 0;
int soilmoisturepercent = 0;
int Relaypin = 13;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  lcd.begin(16, 2);
  pinMode(Relaypin, OUTPUT);
}

void loop() {
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  Serial.print("Soil Moisture Sensor Value: ");
  Serial.println(soilMoistureValue);

  soilmoisturepercent = map(soilMoistureValue,AirValue, WaterValue, 0, 100);
  
  if (soilmoisturepercent >= 100) {
    Serial.println("Soil Moisture: 100%");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print("100 %");
    delay(1000); // Waits for 1 second
    digitalWrite(Relaypin, LOW); // Makes the signal low
    delay(250);
    lcd.clear();
  }
  else if (soilmoisturepercent <= 0) {
    Serial.println("Soil Moisture: 0%");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print("0 %");
    digitalWrite(Relaypin, HIGH); // Sends high signal 
    delay(250); // Waits for 1 second
    digitalWrite(Relaypin, LOW); // Makes the signal low
    delay(250);
    delay(250);
    lcd.clear();
  }
  else if (soilmoisturepercent > 0 && soilmoisturepercent < 100) {
    Serial.print("Soil Moisture: ");
    Serial.print(soilmoisturepercent);
    Serial.println("%");
    lcd.setCursor(0, 0);
    lcd.print("Soil Moisture");
    lcd.setCursor(0, 1);
    lcd.print(soilmoisturepercent);
    lcd.print(" %");
    if (soilmoisturepercent < map(ThresholdValue, 350, 500, 0, 100)) {
      digitalWrite(Relaypin, HIGH); // Sends high signal 
      delay(1000); // Waits for 1 second
      digitalWrite(Relaypin, LOW); // Makes the signal low
      delay(1000);
    }
    delay(250);
    lcd.clear();
  }
}
