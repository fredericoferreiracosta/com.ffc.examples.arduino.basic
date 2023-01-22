/*
    Required libraries:
      - RadioHead
        http://www.airspayce.com/mikem/arduino/RadioHead/
        https://github.com/adafruit/RadioHead
*/
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

const int TRANSMITTER_PIN = 8;
const int TRANSMISSION_DELAY = 1000;
RH_ASK driver(2000, 0, TRANSMITTER_PIN, 0 , true);

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting...");

    if (!driver.init())
    {
        Serial.println("Init failed.");
    }

    Serial.println("Started!");
}

void loop()
{
    const char *msg = "Hello World!";
    driver.send((uint8_t *) msg, strlen(msg));
    driver.waitPacketSent();
    delay(TRANSMISSION_DELAY);
}
