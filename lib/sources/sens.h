#ifndef M_SENS
#define M_SENS
#define PIN_POWERSOURCE 32
#define PIN_DHT22 21

#define DHTTYPE DHT22

#include<Arduino.h>

class Sens{
public:
void init();
float readInternalTemperature();
float readPowerSource();
float readHumidity();
float readTemperature();
};
#endif