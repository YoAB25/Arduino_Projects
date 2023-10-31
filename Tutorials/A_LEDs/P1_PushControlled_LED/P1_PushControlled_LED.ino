#define PIN_BUTT 3
#define PIN_LED 11

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_BUTT, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(PIN_BUTT);
  Serial.print("BUTT State : ");
  Serial.println(buttonState);
  if(buttonState == HIGH){
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }


}