const int LED = 13;
const int BUTTON = 8;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  digitalWrite(LED, LOW);
}

void loop()
{
  int inputValue = digitalRead(BUTTON);

  if (inputValue == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
