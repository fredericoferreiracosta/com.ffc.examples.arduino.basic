#include <Servo.h>

#define SERVO_PIN 8
#define BUTTON_PIN 7
#define SERVO_ANGLE 180

Servo servo;

void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT);
    servo.attach(SERVO_PIN);
}

void loop()
{
    int inputValue = digitalRead(BUTTON_PIN);

    if (inputValue == HIGH) {
        Serial.println("Button pressed");
        servo.write(SERVO_ANGLE);
        delay(5000);
    }
    else
    {
        Serial.println("Button not pressed");
    }
    servo.write(0);
}
