#define LED_PIN 7

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(100);
  digitalWrite(LED_PIN, LOW);
  delay(100);
}


