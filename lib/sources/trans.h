#ifndef M_TRANS
#define M_TRANS
#include <Arduino.h>

class Trans
{
private:
    const char *WIFISSID;
    const char *WIFIPassword;
    const char *MQTTID;
    const char *MQTTUser;
    const char *MQTTPassword;
    const char *MQTTHOST;
    uint16_t MQTTPort;
    bool connect();

public:
    void init(const char *WIFISSID, const char *WIFIPassword, const char *MQTTHOST, const char *MQTTID, const char *MQTTUser, const char *MQTTPassword, uint16_t MQTTPort);
    bool publish(String topic, String data);
    bool publishSensor(float internalTemperature, float powerSource, float temperature, float humidity);
};

#endif