#include <Arduino.h>
#include <trans.h>
#include <sens.h>

const char *WIFI_SSID = "Your WiFi SSID"; //Your WiFi SSID
const char *WIFI_PASSWORD = "Your WiFi Password"; //Your WiFi Password
const char *MQTT_ID = "Your MQTT ID"; //Your MQTT ID
const char *MQTT_USER = "Your MQTT User"; //Your MQTT User
const char *MQTT_PASSWORD = "Your MQTT Password"; //Your MQTT Password
const char *MQTT_HOST = "Your MQTT HOST"; //Your MQTT HOST
const uint16_t MQTT_PORT = 1883; //Your MQTT Port

const uint16_t tInterval = 1000;

Trans trans;
Sens sens;

void setup()
{
  Serial.begin(115200);
  trans.init(WIFI_SSID, WIFI_PASSWORD, MQTT_HOST, MQTT_ID, MQTT_USER, MQTT_PASSWORD, MQTT_PORT);
  sens.init();
}

void loop()
{
  float internalTemperature = sens.readInternalTemperature();
  float powerSource = sens.readPowerSource();
  float temperature = sens.readTemperature();
  float humidity = sens.readHumidity();
  trans.publishSensor(internalTemperature, powerSource, temperature, humidity);
  delay(tInterval);
}