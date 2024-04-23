#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Connect to WiFi
void wifiConnect(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {delay(1000); Serial.println("Connecting...");}
  Serial.println("Connected to the WiFi network");
}

void wifiRequest(String url) {
  HTTPClient http;
  http.begin(url);
  
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    
    if (url == apiUrl) {
      wifiExtractQuote(payload);
    } else if (url == apiUrl2) {
      wifiExtractAffirmation(payload);
    }
  } else {
    Serial.print("Error in HTTP request: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

//Chat GPT helped with this
void wifiExtractQuote(String payload) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, payload);
  
  if (error) {
    Serial.print("deserializeJson() failed for quote: ");
    Serial.println(error.c_str());
    return;
  }

  content = (const char*)doc[0]["content"];
  author = (const char*)doc[0]["author"];

  Serial.print("content:"); Serial.println(content);
  Serial.print("author:"); Serial.println(author);
}
//Chat GPT helped with this
void wifiExtractAffirmation(String payload) {
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, payload);
  
  if (error) {
    Serial.print("deserializeJson() failed for affirmation: ");
    Serial.println(error.c_str());
    return;
  }

  affirmation = (const char*)doc["affirmation"];

  Serial.print("affirmation:"); Serial.println(affirmation);
}
