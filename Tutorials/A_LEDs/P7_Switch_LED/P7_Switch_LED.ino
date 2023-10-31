#define BUTT_PIN 10
#define LED_PIN 3

int press_delay = 5;                    // Predefine press delay to light the 
unsigned long lastPressTime = 0;        // Define a last time pressed button 
boolean ledState = LOW;                 // led state initialized to off

void setup() {
  pinMode(BUTT_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int butt_state = digitalRead(BUTT_PIN);
  unsigned long currentTime = millis();    // Get the current time

  if (butt_state == LOW) {
    // Button is not pressed
    lastPressTime = 0;                     // Expected because when butt was not pressed lat time is 0
  } else if (butt_state == HIGH && lastPressTime == 0) {
    // Button has just been pressed
    lastPressTime = currentTime;           // If we press the button, we set the press time to the current time -> millis   (Used later to compare millis()-lastpressedtime >? 5)
  }

  if (lastPressTime != 0 && currentTime - lastPressTime >= press_delay * 1000) {
    ledState = HIGH;
  }

  if (butt_state == HIGH && ledState == HIGH && currentTime - lastPressTime <= 500) {
    // Button is pressed and LED is on, turn off the LED if the button is pressed again within 500ms
    ledState = LOW;
    lastPressTime = 0; // Reset lastPressTime to prevent immediate turn-on
  }
   // Write the ledState into the LED_PIN using the digitalWrite 
   digitalWrite(LED_PIN, ledState);
}
