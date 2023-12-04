#include <SoftwareSerial.h>

SoftwareSerial mySerial(18, 19); // RX, TX

void setup() {
  Serial.begin(9600);   // Initialize hardware serial
  mySerial.begin(9600); // Initialize software serial
}

void loop() {
  // Read data from the PC using software serial
  if (mySerial.available() > 0) {
    char receivedChar = mySerial.read();  // Read a character from software serial

    // Process the received character (for example, print it to the hardware serial)
    Serial.print("Received: ");
    Serial.println(receivedChar);

    // Validate checksum
    if (validateChecksum(receivedChar)) {
      Serial.println("Checksum is valid!");
    } else {
      Serial.println("Checksum is invalid!");
    }
  }

  // Your main code goes here
}

bool validateChecksum(char data) {
  // Implement your checksum validation logic here
  // For simplicity, let's say the checksum is the ASCII value of the received character
  int receivedChecksum = int(data);
  return (receivedChecksum == calculateChecksum(data));
}

int calculateChecksum(char data) {
  // For simplicity, let's say the checksum is the ASCII value of the character
  return int(data);
}
