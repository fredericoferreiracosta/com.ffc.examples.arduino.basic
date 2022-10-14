#include "SegmentDisplay.h"

SegmentDisplay segmentDisplay(2, 3, 4, 5, 6, 7, 8, 9);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  //segmentDisplay.testDisplay();
  for (int i = 5; i > 0; i--) {
  	segmentDisplay.displayHex(i, false);
    delay(400);
  }
}

void loop()
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}