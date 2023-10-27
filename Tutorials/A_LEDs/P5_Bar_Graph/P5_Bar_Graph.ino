#define READ_STATE A0

int pins[] = {2,3,5,6,9,11};
int tot_pins = sizeof(pins) / sizeof(pins[0]);

void setup(){
    Serial.begin(9600);
    pinMode(READ_STATE, INPUT);
    for (int i=0; i<tot_pins; i++){
        pinMode(pins[i], OUTPUT);
    }
    
}

void loop(){
    // Serial.println(analogRead(READ_STATE));
    int value = analogRead(READ_STATE);
    int mapping_values = map(value, 0, 1023, 0, tot_pins);
    // for (int i=0; i<tot_pins; i++){
    //     analogWrite(pins[i], mapping_values);
    // }
    for(int i=0; i<tot_pins; i++){
        if(i < mapping_values){             // If i==0 and mapping_value=1 we'll get only one 'the first led pin' that is light on and so on
            digitalWrite(pins[i], HIGH);
        } else {
            digitalWrite(pins[i], LOW);
        }
    }
    Serial.print(mapping_values);
    Serial.print("_");
    Serial.println(value);
}