#define POT_ANA A0
#define PIN_RED 3
#define PIN_BLUE 7

void setup(){
    Serial.begin(9600);
    pinMode(POT_ANA, INPUT);
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
}

void loop(){
    int potVal = analogRead(POT_ANA);
    Serial.println(potVal);

    int mapping_values = map(potVal, 0, 1023, 10, 500); // Delay
    
    digitalWrite(PIN_RED, HIGH);
    delay(mapping_values);
    digitalWrite(PIN_BLUE, HIGH);
    delay(mapping_values);
    digitalWrite(PIN_RED, LOW);
    delay(mapping_values);
    digitalWrite(PIN_BLUE, LOW);
    delay(mapping_values);

}