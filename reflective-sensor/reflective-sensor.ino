const int LED = 13;
const int SENSOR = 2;
const int DELAY_TIME = 100;

void setup()
{
  Serial.begin(9600);
  Serial.write("Starting...");
  Serial.println();

  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

  digitalWrite(LED, LOW);
}

void loop()
{
  int inputValue = digitalRead(SENSOR);

  if (inputValue == LOW) {
    Serial.write("true");
    Serial.println();
    digitalWrite(LED, HIGH);
  } else {
    Serial.write("false");
    Serial.println();
    digitalWrite(LED, LOW);
  }

  delay(DELAY_TIME);
}
