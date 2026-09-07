//Codigo principal 
// Channel ID: 3464038


#include <WiFi.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <Adafruit_GFX.h>
#include <U8g2lib.h>

#include <ThingSpeak.h>


const char* ssid = "LaboratorioDelta";
const char* password = "labdelta21";

unsigned long myChannelNumber = 3464038;
const char* WriteAPIKey = "I94PJNZYX31GQFPE";


WiFiClient client;

#define SDA_PIN D4
#define SCL_PIN D5

Adafruit_BME280 bme;

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C oled(U8G2_R0); //Pantalla

unsigned long tiempoMedicion = 0;
unsigned long tiempoThingSpeak = 0;

const unsigned long intervaloMedicion = 1000;   // 1 segundo
const unsigned long intervaloThingSpeak = 15000; // 15 segundos

float temperatura; //guardar variables
float humedad;
float presion;


void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  oled.begin();

  if (!bme.begin(0x76)) {
    Serial.println("No se encontro el BME280");
    while (1);
  }

  Serial.println("BME280 encontrado");
  Serial.print("Conectando a WiFi"); //wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop(){
   unsigned long tiempoActual=millis();
   if (tiempoActual - tiempoMedicion >= intervaloMedicion){
      tiempoMedicion = tiempoActual;

      temperatura = bme.readTemperature();
      humedad = bme.readHumidity();
      presion = bme.readPressure()/100.0F; 

      Serial.println("Temperatura: ");
      Serial.println(temperatura);
      Serial.println(" C");

      Serial.println("Humedad: ");
      Serial.println(humedad);
      Serial.println(" %");

      Serial.println("Presion: ");
      Serial.println(presion);
      Serial.println(" hPa");

      oled.clearBuffer();
      oled.setFont(u8g2_font_6x10_tf);

      oled.setCursor(0, 10);
      oled.print("T: ");
      oled.print(temperatura, 2);
      oled.print(" C");

      oled.setCursor(0, 21);
      oled.print("H: ");
      oled.print(thumedad, 2);
      oled.print(" %");
      
      oled.setCursor(0, 32);
      oled.print("P: ");
      oled.print(presion, 2);
      oled.print(" hPa");

      oled.sendBuffer();
   }

   if (tiempoActual - tiempoThingSpeak >= intervaloThingSpeak){
      tiempoThingSpeak = tiempoActual;

      ThingSpeak.setField(1, temperatura);
      ThingSpeak.setField(2, Humedad);
      ThingSpeak.setField(3, Presion);

      int respuesta = ThingSpeak.writeFields(
         myChannelNumber,
         
      )
   }
}
