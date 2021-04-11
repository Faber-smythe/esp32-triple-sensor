void loop() {
  
  /* Fetch temperature */
  tempSensor.requestTemperatures(); 
  float temperatureAsCelsius = tempSensor.getTempCByIndex(0);
  
  /* Fetch humidity */
  const int analogHumidity = analogRead(humiditySensorPin); // 0 <= value <= 4095
  const int humidityAsPercentage = map(analogHumidity, 0, 4095, 0, 100);

  /* Fetch luminosity (Wait for completion with busy-wait delay)*/
  uint16_t lightAsLux;
  if (lightSensor.isConversionCompleted()) {
    lightAsLux = lightSensor.read();
  }
  
  /* Printing serial logs */
  Serial.print("Sending temperature (");
  Serial.print(temperatureAsCelsius);
  Serial.print(" ºC) and light level (");
  Serial.print(lightAsLux);
  Serial.print(" Lux) and humidity level (");
  Serial.print(humidityAsPercentage);
  Serial.print(" %) ...\n");

  /*
   * 
   * Sending LEDs signals for visualization
   * 
   */
  
  /* temperature */
  if(-127 < temperatureAsCelsius && temperatureAsCelsius <= 20){
    LEDThermoLevel(1);
  }else if (20 <= temperatureAsCelsius && temperatureAsCelsius <= 25){
    LEDThermoLevel(2);
  }else if(25 <= temperatureAsCelsius){
    LEDThermoLevel(3);
  }
  /* light */
  if(0 <= lightAsLux && lightAsLux <= 100){
    LEDLightLevel(1);
  }else if (100 <= lightAsLux && lightAsLux <= 700){
    LEDLightLevel(2);
  }else if(700 <= lightAsLux && lightAsLux <= 40000){
    LEDLightLevel(3);
  }else if(40000 <= lightAsLux){
    LEDLightLevel(4);
  }
  /* humidity */
  if(0 <= humidityAsPercentage && humidityAsPercentage <= 5){
    LEDHumidLevel(1);
  }else if (5 <= humidityAsPercentage && humidityAsPercentage <= 20){
    LEDHumidLevel(2);
  }else if(20 <= humidityAsPercentage){
    LEDHumidLevel(3);
  }
  
  /* Sending HTTP request */
  postSensorData(temperatureAsCelsius, lightAsLux, humidityAsPercentage);
  
  Serial.println("\n-----------------------\n");
  delay(1000);
}
