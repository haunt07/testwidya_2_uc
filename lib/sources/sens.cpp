#include "sens.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

uint32_t lastTimeRead;

DHT dht(PIN_DHT22, DHTTYPE);

void Sens::init()
{
    pinMode(PIN_POWERSOURCE, INPUT);
    Serial.println("Test");
    lastTimeRead = millis();
    dht.begin();
}

float Sens::readInternalTemperature()
{
    return temperatureRead();
}

float Sens::readPowerSource()
{
    return analogRead(PIN_POWERSOURCE) * 3.3 / 4095;
}

float Sens::readTemperature()
{
    return dht.readTemperature();
}

float Sens::readHumidity()
{
    return dht.readHumidity();
}