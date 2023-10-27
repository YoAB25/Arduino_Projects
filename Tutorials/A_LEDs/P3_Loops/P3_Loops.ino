int pins[] = {13,2,3,4,5,6,7};
int tot_pins = sizeof(pins) / sizeof(pins[0]);

void setup()
{
  Serial.begin(9600);
  // This pin acts like an output
  for (int i=0; i<tot_pins; i++){
    pinMode(pins[i], OUTPUT);
  }


}

void loop()
{
  static int k = 0;
  Serial.println("This is the ");
  Serial.print(k);
  Serial.print(" loop");

  for (int l=0; l<tot_pins; l++){
    digitalWrite(pins[l], HIGH);
    delay(100);
    digitalWrite(pins[l], LOW);
    delay(100);
  }
  for (int l=tot_pins-1; l>=0; l--){
    digitalWrite(pins[l], HIGH);
    delay(100);
    digitalWrite(pins[l], LOW);
    delay(100);
  }
  
}


