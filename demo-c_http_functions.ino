
/* More information in guides like this : https://randomnerdtutorials.com/esp32-http-get-post-arduino/ */
void postSensorData(float intemperatureAsCelsius, int lightAsLux, int humidityAsPercentage){
  
  if(WiFi.status()== WL_CONNECTED){   

    /* Instantiate our request object (it will contain headers, body, and servers reponses) */
    HTTPClient http;
    
    /* Set request target */
    http.begin(API_url);  

    /* Set http headers */
    http.addHeader("Content-Type", "application/json");
    http.addHeader("User-Agent","Espressif");
    http.addHeader("Accept", "*/*");
    http.addHeader("Accept-Encoding", "gzip, deflate, br");
    http.addHeader("Connection","keep-alive");     
    
    /* Build the request body as a serialized (= stringified) JSON - values are concatenated */


    /* Send the actual POST request to the API */
    int httpResponseCode = http.POST("{\"temp\":\"" + String(intemperatureAsCelsius) + "\",\"humid\":\"" + String(humidityAsPercentage) + "\",\"light\":\"" + String(lightAsLux) + "\"}");   

    /* Check for errors */
    if(httpResponseCode>0){
      
      /* Get and print the response from the server */
      String response = http.getString();                       
      Serial.println(response);
      
    }else{
      String error = "";
      switch (httpResponseCode) {
        case -1: error = "ERROR_CONNECTION_REFUSED"; break;
        case -2: error = "ERROR_SEND_HEADER_FAILED"; break;
        case -3: error = "ERROR_SEND_PAYLOAD_FAILED"; break;
        case -4: error = "ERROR_NOT_CONNECTED"; break;
        case -5: error = "ERROR_CONNECTION_LOST"; break;
        case -6: error = "ERROR_NO_STREAM"; break;
        case -7: error = "ERROR_NO_HTTP_SERVER"; break;
        case -8: error = "ERROR_TOO_LITTL_RAM"; break;
        case -9: error = "ERROR_ENCODING"; break;
        case -10: error = "ERROR_STREAM_WRITE"; break;
        case -11: error = "ERROR_READ_TIMEOUT"; break;
        default: error = "UNKOWN_ERROR"; break;
      }
      Serial.println("Error on sending POST: " + error);
      Serial.println("If the error persists, 1) check that server's running 2) your network setting in declarations file 3) try to press 'RESET' on the board.");
    }
    
    /* Free resources */
    http.end();  
  }else{
    // Unlikely case where connection got spontanenously lost
    Serial.println("Error in WiFi connection. Attempt to reconnect...");
    WiFi.begin(ssid, password);   
  }
}
