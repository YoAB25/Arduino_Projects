int speakerPin = 9; // Pin connected to the piezo
int length = 15; // Number of notes
char notes[] = "ccggaagffeeddc "; // A space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
 for (long i = 0; i < duration * 1000L; i += tone * 2) {
 digitalWrite(speakerPin, HIGH);
 delayMicroseconds(tone);
 digitalWrite(speakerPin, LOW);
 delayMicroseconds(tone);
 }
}
// Set timeHigh value to specific notes
void playNote(char note, int duration) {
 char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
 int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 for (int i = 0; i < 8; i++) { // Play tone that corresponds
 // to note name
 if (names[i] == note) {
 playTone(tones[i], duration);
 }
 }
}
void setup() {
 pinMode(speakerPin, OUTPUT); // Set speakerPin as output
}
// Play the tune
void loop() {
 for (int i = 0; i < length; i++) {
 if (notes[i] == ' ') {
 delay(beats[i] * tempo); // Rest
 }
 else {
 playNote(notes[i], beats[i] * tempo);
 }
 delay(tempo / 2); // Pause between notes
 }
}