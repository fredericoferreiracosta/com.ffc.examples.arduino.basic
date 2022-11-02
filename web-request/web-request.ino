/*
    Required boards:
      - ESP8266 http://arduino.esp8266.com/stable/package_esp8266com_index.json
*/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define SHA1_FINGERPRINT "3D B3 98 0A 82 86 25 5C E8 12 20 C3 6E 6F 15 83 8B C5 8F 3A" // You can get this opening the HTTPS link in your browser and checking the certificate details
#define JSON_SIZE_LIMIT = 1024
#define SSID "<WIFI_SSID>"
#define PASSWORD "<WIFI_PASSWORD>"

const String HOST = "https://swapi.dev";

void setup()
{
  Serial.begin(115200);

  connectToWifi();

  WiFiClientSecure client;
  HTTPClient http;

  client.setFingerprint(SHA1_FINGERPRINT);
  http.begin(client, HOST + "/api/people/1");

  Serial.println("Requesting data from server...");
  int responseCode = http.GET();
  if (responseCode == HTTP_CODE_OK)
  {
    Serial.println("Success");
    Serial.println(http.getString());
  }
  else
  {
    Serial.println("Error on HTTP request. Error code: " + String(responseCode));
  }

  Serial.println("Done!");
  http.end();
}

void loop()
{
}

void connectToWifi()
{
  Serial.println("Connecting to " + String(SSID));
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Waiting to connect...");
  }

  Serial.println("Connected! IP address: " + WiFi.localIP().toString());
}
