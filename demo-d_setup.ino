void setup() {
  Serial.begin(115200);
  
  /* Set all GPIO pins to output mode */
  for (int i=0; i<sizeof leds; i++) {
    pinMode(leds[i], OUTPUT);
  }

  /* Booting Wifi connection */
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    /* calling leds function inbetween to visualize loading */
    if(WiFi.status() != WL_CONNECTED){Serial.print("."); oneOn(26); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(25); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(33); delay(100);}
    if(WiFi.status() != WL_CONNECTED){Serial.print("."); oneOn(27); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(14); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(12); delay(100);}
    if(WiFi.status() != WL_CONNECTED){Serial.print("."); oneOn(13); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(15); delay(100);}
    if(WiFi.status() != WL_CONNECTED){oneOn(4); delay(100);}
  }
  Serial.println();
  Serial.print("Connected ! IP address: ");
  Serial.println(WiFi.localIP());
  ledLoaded();

  /* Booting the lightSensor I2C bus */
  Wire.begin();
  lightSensor.begin(ModeContinuous, ResolutionMid);
  // Start conversion
  lightSensor.startConversion();

  /* Booting the tempSensor OneWire bus */
  tempSensor.begin();
  Serial.print("Temperature sensor DS18B20 ready.\n--\n--\n");
}
