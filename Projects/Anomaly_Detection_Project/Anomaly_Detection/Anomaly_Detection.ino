#define LED_PIN 13

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(3000);
  digitalWrite(LED_PIN, LOW);
  delay(3000);
}

