#define RED_PIN 8
#define GREEN_PIN 11
#define YELLOW_PIN 6
#define BUTT_PIN 3

unsigned long lastTime = 0;
unsigned long greenRedTime = 10000;  // 10 seconds for red and green
unsigned long yellowTime = 5000;    // 5 seconds for yellow
unsigned long specialWaitTime = 3000; // 3 seconds to wait after the button press

boolean buttonPressed = false;
unsigned long buttonPressTime = 0;

void green_light(){
    // Counts for 10 seconds
    for (int i=0; i<10; i++){
        int buttonState = digitalRead(BUTT_PIN);
        // Serial.println(buttonState);
        // If the button wasn't pressed just wait for a 1s and re-take the loop (1s*10 -> 10s)
        if(buttonState == 0){
            Serial.print(i);
            delay(1000);
            Serial.print(", ");
        // Else if the button as pressed -> Wait for 500ms and then end the function to turn red allow crossing
        } else if (buttonState == 1){
            Serial.println("Someone is crossing ...");
            delay(500);
            return;
        }

    }
}

void setup() {
    Serial.begin(9600);
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BUTT_PIN, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
    digitalWrite(RED_PIN, HIGH);
    delay(10000);
    digitalWrite(RED_PIN, LOW);
    
    digitalWrite(GREEN_PIN, HIGH);
    Serial.println("GREEN");
    green_light();

    digitalWrite(GREEN_PIN, LOW);
    Serial.println("YELLOW");

    digitalWrite(YELLOW_PIN, HIGH);
    delay(1000);
    digitalWrite(YELLOW_PIN, LOW);
    Serial.println("RED");

}
