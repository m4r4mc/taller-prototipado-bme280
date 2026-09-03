//Codigo principal 
// Channel ID: 3464038


#include <WiFi.h>
#include <Wire.h> // i2c

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <Adafruit_GFX.h>
#include <U8g2lib.h> //pantalla

#include <ThingSpeak.h>

const char* ssid = "LaboratorioDelta"; //wifi
const char* password = "labdelta21";

unsigned long myChannelNumber = 3464038; //thingspeak
const char* WriteAPIKey = "I94PJNZYX31GQFPE"; //esto se quita despues
WiFiClient client;


#define SDA_PIN D4;
#define SCL_PIN D5;

Adafruit_BME280 bme;

U8G2_SSD1306_128X32_UNIVISION_F_HW_12C oled(U8G2_R0) //pantalla

unsigned long tiempoAnterior = 0; 
const unsigned long intervalo = 1000; 

Wire.begin(SDA_PIN, SCL_PIN);

//screen
oled.begin();
oled.clearBuffer();
oled.setFont(u8g2_font_6x10_tf);
oled.drawStr(0, 10, "Iniciando");
oled.senBuffer();

if (!bme.begin(0x76)){ //bme280
   Serial.println("BME280 no encontrado");
   oled.clearBuffer();
   oled.drawStr(0, 10,"Error BME280");
   oled.sendBuffer();

   while(1);
}

Serial.println("BME280 iniciando")

Serial.println("Conectando WiFi"); // conexion al wifi
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED);{
   delay(500);
   Serial.println(".");
}

Serial.println();
Serial.println("WiFi conectado");
Serial.println("IP: ");
Serial.println(wiFi.localIP());

ThingSpeak.begin(client);

oled.clearBuffer();
oled.drawStr(0, 10, "Iniciando");
oled.sendBuffer();
delay(2000);

