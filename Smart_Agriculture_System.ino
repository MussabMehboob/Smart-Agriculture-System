#define BLYNK_PRINT Serial
#include <C:\Users\DELL\Documents\ArduinoData\packages\esp32\hardware\esp32\1.0.6\libraries\WiFi\src\WiFi.h>    
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>     //Different Libraries that are required for our smart agriculture systme
//#include <DHT.h>
//#include "DHT.h"

#define DHTPIN 21
#define DHTTYPE DHT11   // DHT 11

const int waterLevelSensor = 2;
const int moistureLevelSensor = 15;   //Defining different required variables
const int relay = 23;

int waterLevel;              
int moistureLevel;

//DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


char auth[] = "375BNAvho9GcWEE7qLbY90TOT4wmmvKR";     //authentication token sent from the blynk app

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OPPO";     //Enter your Wifi Credentials here
char pass[] = "punjab12"; 


void sendSensor1Data()
{
  float h =60;
  //dht.readHumidity();
  float t = 25;
  //dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
    
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");    //This function is used to take values of first two sensors
    return;
  }               //Humidity and Temperature sensors value is taken through this function

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);

}

void sendSensor2Data()
{
  //waterLevel = analogRead(waterLevelSensor);
  //waterLevel = map(waterLevel,0,2000,0,20);
  //moistureLevel = analogRead(moistureLevelSensor);
  //moistureLevel = map(moistureLevel,0,4000,0,20);        //This function is used to take value of Soil and Water sensor
  

  Blynk.virtualWrite(V7,30);
  Blynk.virtualWrite(V8, 25);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
   
  //dht.begin();

    // Setup a function to be called every second
  timer.setInterval(2000L, sendSensor1Data);      //First function is called every 2 seconds
  timer.setInterval(5000L, sendSensor2Data);      //Second function is called every 5 seconds

}
void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();    }
