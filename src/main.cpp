#include <Arduino.h>
#include <trans.h>
#include <sens.h>

const char *WIFI_SSID = "WiFi Momu";
const char *WIFI_PASSWORD = "fiffla123";
const char *MQTT_ID = "test2";
const char *MQTT_USER = "user";
const char *MQTT_PASSWORD = "admin";
const char *MQTT_HOST = "52.221.187.140";

const uint16_t tInterval = 1000;

Trans trans;
Sens sens;

void setup()
{
  Serial.begin(115200);
  trans.init(WIFI_SSID, WIFI_PASSWORD, MQTT_HOST, MQTT_ID, MQTT_USER, MQTT_PASSWORD);
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