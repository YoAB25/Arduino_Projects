#define X_PIN A0
#define Y_PIN A1
#define SWITCH_PIN 2

int x_val = 0;
int y_val = 0;
int switch_val = 0;

void setup(){
    Serial.begin(9600);
    pinMode(X_PIN, INPUT);
    pinMode(Y_PIN, INPUT);
    pinMode(SWITCH_PIN, INPUT);
    digitalWrite(SWITCH_PIN, HIGH);
}

void loop(){
    x_val = analogRead(X_PIN);
    y_val = analogRead(Y_PIN);
    switch_val = digitalRead(SWITCH_PIN);
    delay(500);
    Serial.print("X_axis : ");
    Serial.println(x_val);
    Serial.print("Y_axis : ");
    Serial.println(y_val);
    Serial.print("S_axis : ");
    Serial.println(switch_val);
    Serial.println("---");
}