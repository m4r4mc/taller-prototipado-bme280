// codigo principal
// Channel ID: 3464038


#include <WiFi.h>
#include <Wire.h> // i2c
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ThingSpeak.h>

const char* ssid = "Nombre red WiFi";
const char* password = "contra";
unsigned long myChannelNumber = 3464038;
const char* WriteAPIKey = "I94PJNZYX31GQFPE";

#define time_sleep 300
#define factor 1000000ULL
#define SDA_PIN D4;
#define SCL_PIN D5;


#Adafruit_BME280;
#WiFiClient client;

void setup(){
    Serial.begin(115200);
    delay(1000);
    Serial.println("XIAO reconocido")

    Wire.begin(SDA_PIN, SLC_PIN);
    
}
