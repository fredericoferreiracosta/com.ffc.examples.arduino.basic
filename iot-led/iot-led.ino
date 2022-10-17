/*
    This will turn a LED on and off based on a web request.

    Required boards:
        - ESP8266 http://arduino.esp8266.com/stable/package_esp8266com_index.json
*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

ESP8266WebServer server(80);

const int LED_PIN = 5;
const int JSON_SIZE_LIMIT = 1024;
const char *ssid = "<WIFI_SSID>";
const char *password = "<WIFI_PASSWORD>";

enum State
{
    on,
    off
};

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    connectToWifi();

    server.on("/led/on", handleLedOn);
    server.on("/led/off", handleLedOff);

    server.begin();
    Serial.println("Server listening");
}

void loop()
{
    server.handleClient();
}

void handleLedOn()
{
    handleLed(on);
}

void handleLedOff()
{
    handleLed(off);
}

void handleLed(State state)
{
    if (server.method() != HTTP_GET)
    {
        server.send(400, "text/html", "Only GET method is allowed");
    }

    if (state == on)
    {
        Serial.println("Turning LED on");
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        Serial.println("Turning LED off");
        digitalWrite(LED_PIN, LOW);
    }

    server.send(200, "text/html", "Done!");
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
