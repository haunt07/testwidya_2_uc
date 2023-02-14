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
    bool connect();

public:
    void init(const char *WIFISSID, const char *WIFIPassword, const char *MQTTHOST, const char *MQTTID, const char *MQTTUser, const char *MQTTPassword);
    bool publish(String topic, String data);
    bool publishSensor(float internalTemperature, float powerSource, float temperature, float humidity);
};

#endif