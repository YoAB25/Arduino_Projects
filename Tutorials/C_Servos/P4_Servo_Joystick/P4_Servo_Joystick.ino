#include <Servo.h>

#define X_PIN A0
#define Y_PIN A1
#define SWITCH_PIN 2
#define SERVO_PIN 7

int x_val = 0;
int y_val = 0;
int switch_val = 0;

Servo my_servo;

void setup(){
    Serial.begin(9600);
    pinMode(X_PIN, INPUT);
    pinMode(Y_PIN, INPUT);
    pinMode(SWITCH_PIN, INPUT);
    digitalWrite(SWITCH_PIN, HIGH);
    my_servo.attach(SERVO_PIN);
}

void loop(){
    x_val = analogRead(X_PIN);
    switch_val = digitalRead(SWITCH_PIN);
    delay(1);
    int wx_val = (180./1023.)*x_val; // Here we cn also use the map(x_val, 0, 1023, 0, 180) if we want ^_^ ...
    my_servo.write(wx_val);


}