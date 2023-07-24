#include <WiFi.h> 
#include <HTTPClient.h>

const char* ssid = "Smart_Methods1";
const char* password = "123456789";

const String url = "https://s-m.com.sa/f.html";
String payload = "";
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(25, OUTPUT);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Fetching " + url + "... ");

  


}

void loop() {
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println();
    Serial.println(payload);
    if( payload == "forward" ){
      digitalWrite(25, HIGH);
    }else if(payload == "backward"){
    }
    else if(payload == "left"){
      digitalWrite(14, HIGH);
    }
    else if(payload == "right"){
      digitalWrite(25, HIGH);
    }
    else{
      digitalWrite(12, LOW);
    }
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }
  
}
