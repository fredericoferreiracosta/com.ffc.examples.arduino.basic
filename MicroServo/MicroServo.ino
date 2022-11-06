#include <Servo.h>

#define SERVO_PIN 8

Servo servo;

void setup()
{
    Serial.begin(9600);
    servo.attach(SERVO_PIN);
}

void loop()
{
    Serial.println("Enter angle:");
    while (Serial.available() == 0) {}
    int angle = Serial.parseInt();
    servo.write(angle);
}
