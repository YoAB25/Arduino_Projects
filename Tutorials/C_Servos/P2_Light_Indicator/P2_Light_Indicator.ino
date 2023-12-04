// Starter code : No specific equation no calculation ...

#include <Servo.h>

#define L_PIN A0
#define SERVO_PIN 7

Servo my_servo;

void setup(){
    Serial.begin(9600);
    pinMode(L_PIN, INPUT);
    my_servo.attach(SERVO_PIN);

}

void loop(){
    // Serial.print("Light intensity : ");
    int val = analogRead(L_PIN);
    val = map(val, 0, 680, 0, 180);

    my_servo.write(val);
    delay(20);
    Serial.println(val);
}