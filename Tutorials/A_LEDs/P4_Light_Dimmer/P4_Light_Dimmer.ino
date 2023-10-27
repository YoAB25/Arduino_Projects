#define READ_STATE A0
#define LED_PIN 3

void setup(){
    Serial.begin(9600);
    pinMode(READ_STATE, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop(){
    // Serial.println(analogRead(READ_STATE));
    int value = analogRead(READ_STATE);
    int mapping_values = map(value, 0, 1023, 0, 255);
    analogWrite(LED_PIN, mapping_values);
    Serial.println(mapping_values);
}