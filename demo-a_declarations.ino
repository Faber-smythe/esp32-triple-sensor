/* Temperature sensor DS18B20 uses 'OneWire' instead of I2C */
#include <OneWire.h>
#include <DallasTemperature.h>

/* Light sensor BH1750 uses I2C (so 'Wire' lib) */
#include <Wire.h>
#include <ErriezBH1750.h>

/* These lib are needed to send http request to the API */
#include <WiFi.h> 
#include <HTTPClient.h>

/*
 * 
 * DEFINING THE NETWORK SETTINGS BELOW /!\ 
 *
 */
const char* ssid = "MyWifi";
const char* password = "MyPassword";

/*
 * DEFINING ENDPOINTS HERE /!\
 */
const String API_url = "MyEndpointURL";

/*
 * Defining the sensor pins (DO NOT EDIT THESE IF YOU'RE USING THE DVIC CLIMATE SENSOR CIRCUIT)
 * Since I2C uses default SCL and SDA pins, lightSensor does not need to specify pins.
 */
const int humiditySensorPin = 39;
const int temperatureSensorPin = 32;


/* Instantiate OneWire and the DallasTemperature sensor */
const int oneWireBus = temperatureSensorPin;
OneWire oneWire(oneWireBus);
DallasTemperature tempSensor(&oneWire);

/* Instantiate the BH1750 luminosity sensor */
BH1750 lightSensor(LOW);
