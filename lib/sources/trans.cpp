#include "trans.h"
#include <WiFi.h>
#include <MQTT.h>

WiFiClient net;
MQTTClient client;

void Trans::init(const char *WIFISSID, const char *WIFIPassword, const char *MQTTHOST, const char *MQTTID, const char *MQTTUser, const char *MQTTPassword, uint16_t MQTTPort)
{
    this->WIFISSID = WIFISSID;
    this->WIFIPassword = WIFIPassword;
    this->MQTTHOST = MQTTHOST;
    this->MQTTID = MQTTID;
    this->MQTTUser = MQTTUser;
    this->MQTTPassword = MQTTPassword;
    this->MQTTPort = MQTTPort;
    WiFi.begin(WIFISSID, WIFIPassword);
    client.begin(MQTTHOST, MQTTPort, net);
}

bool Trans::connect()
{
    uint32_t tCheck = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - tCheck >= 10000)
        {
            return false;
        }
        WiFi.disconnect();
        WiFi.reconnect();
        delay(1000);
    }
    tCheck = millis();
    while (!client.connect(this->MQTTID, this->MQTTUser, this->MQTTPassword))
    {
        if (millis() - tCheck >= 10000)
        {
            return false;
        }
        delay(1000);
    }
    return true;
}

bool Trans::publish(String topic, String data)
{
    if (!this->connect())
    {
        return false;
    }
    return client.publish(topic, data);
}

bool Trans::publishSensor(float internalTemperature, float powerSource, float temperature, float humidity)
{
    String data = "{\"internal_temperature\":" + String(internalTemperature) +
                  ",\"power_source\":" + String(powerSource) +
                  ",\"temperature\":" + String(temperature) +
                  ",\"humidity\":" + String(humidity) + "}";
    return this->publish("/2-mqtt", data);
}