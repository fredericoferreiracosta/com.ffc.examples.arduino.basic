#include <IRremote.hpp>

const int IR_SEND_PIN = 8;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");

  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  Serial.println("Sending IR signal...");
  IrSender.sendNEC(0x20DF10EF, 32); // Google your TV codes, this one is for a LG model
  delay(10000);
}
