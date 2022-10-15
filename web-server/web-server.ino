/*
  Required libs:
    - https://github.com/bblanchon/ArduinoJson
  
*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server(80);

const int JSON_SIZE_LIMIT = 1024;
const char *ssid = "<SSID>";
const char *password = "<YOUR_PASSWORD>";

void setup()
{
  Serial.begin(115200);

  connectToWifi();

  server.on("/", handleIndex);

  server.begin();
  Serial.println("Server listening");
}

void loop()
{
  server.handleClient();
}

void handleIndex()
{
  Serial.println("Request received");

  if (server.method() == HTTP_GET)
  {
    server.send(200, "text/html", "Hello World!");
  }

  if (server.method() == HTTP_POST)
  {
    String body = server.arg("plain");
    Serial.println("Body content: " + body);

    DynamicJsonDocument doc = deserialize(body);
    // String key1 = doc["key1"];
    // Serial.println("Attribute key1 from JSON: " + key1);

    server.send(200, "text/html", "Body received: " + body);
  }

  server.send(200, "text/plain", "Default response, for other methods");
}

void connectToWifi()
{
  Serial.println("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Waiting to connect...");
  }

  Serial.println("Connected! IP address: " + WiFi.localIP().toString());
}

DynamicJsonDocument deserialize(String json)
{
  Serial.println("Deserializing JSON");
  DynamicJsonDocument doc(JSON_SIZE_LIMIT);

  deserializeJson(doc, json);

  return doc;
}
