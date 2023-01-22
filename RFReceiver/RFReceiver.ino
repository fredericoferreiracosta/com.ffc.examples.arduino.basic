/*
    Required libraries:
      - RadioHead
        http://www.airspayce.com/mikem/arduino/RadioHead/
        https://github.com/adafruit/RadioHead
*/
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

const int RECEIVER_PIN = 8;
RH_ASK driver(2000, RECEIVER_PIN);

void setup()
{
    driver.init();

    Serial.begin(9600);
    Serial.println("Starting...");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen))
    {
      Serial.print("Message received: ");
      Serial.println((char*) buf);
    }
}
