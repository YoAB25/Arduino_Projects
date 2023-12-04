#include <Servo.h>

#define POT_ANA A0
#define SERVO_PIN 9

Servo my_servo;

void setup(){
    Serial.begin(9600);
    pinMode(POT_ANA, INPUT);
    my_servo.attach(SERVO_PIN);
}

void loop(){
    int val = analogRead(POT_ANA);
    val = map(val, 0, 1023, 0, 180);
    my_servo.write(val);
    delay(15);
    Serial.print("Angle : ");
    Serial.println(my_servo.read());
}

// Make a code that rotates the servo from 0<->180 degrees

// void loop(){
//     for(int pos=0; pos<=180; pos++){
//         my_servo.write(pos);
//         delay(15);
//     }
//     for(int pos=180; pos>=0; pos--){
//         my_servo.write(pos);
//         delay(15);
//     }



// }