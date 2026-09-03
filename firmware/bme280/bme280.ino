//Codigo principal 
// Channel ID: 3464038


#include <WiFi.h>
#include <Wire.h> // i2c
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ThingSpeak.h>
#include <U8g2lib.h> //pantalla

const char* ssid = "LaboratorioDelta";
const char* password = "labdelta21";
unsigned long myChannelNumber = 3464038;
const char* WriteAPIKey = "I94PJNZYX31GQFPE"; //el write api se borra despues

const int sleepTime = 10000; //ajustar tiempo con bateria

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
    
    //Inicializar Adafruit_BME280

     bool bm0k = b,e.begin(0x76, &Wire);   //comunica con bme280 n i2c 0x76
     if (!bme0k){
        Serial.println("Error: no se detecta BME280");
     } else{
        Serial.println("BME280 conectado")
     }
     
     //leer bme280
     float temp = 0, hum =0, p = 0;
     if (bme0k){
        temp = bme.readTemperature();
        hum = bme.readHumidity();
        p = bme.readPressure()/100F;
     }
     //mostrar datos
     //conexion WiFi
     //enviar datos a ThingSpeak
     ThingSpeak.setField(1, temp);
     ThingSpeak.setField(2, hum);
     ThingSpeak.setField(3, p);

     //apagar


     //deep time_sleep
     //thingspe


void loop(){

}
