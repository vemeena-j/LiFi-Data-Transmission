#define LED_PIN 23

String receivedMessage = "";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("================================");
  Serial.println("       Li-Fi DATA TRANSMISSION");
  Serial.println("================================");
  Serial.println("Enter your message:");
}

// Simulate optical transmission
int transmitBit(int bit) {

  // LED represents optical signal
  digitalWrite(LED_PIN, bit ? HIGH : LOW);

  delay(100);

  // Software optical channel
  // Receiver gets the same transmitted bit
  return bit;
}

// Convert byte into 8 bits
void transmitByte(byte data) {

  String binary = "";

  for (int i = 7; i >= 0; i--) {

    int bit = (data >> i) & 1;

    binary += String(bit);

    // Transmitter sends bit
    int receivedBit = transmitBit(bit);

    // Receiver decodes bit
    if (receivedBit == bit) {
      // Store received bit
    }
  }

  Serial.print(binary);
}

// Send complete message
void sendMessage(String message) {

  receivedMessage = "";

  Serial.println();
  Serial.println("--------------------------------");
  Serial.print("Transmitting: ");
  Serial.println(message);

  Serial.println("Binary Data:");

  // TRANSMITTER
  for (int i = 0; i < message.length(); i++) {

    Serial.print(message[i]);
    Serial.print(" = ");

    transmitByte(message[i]);

    Serial.println();
  }

  digitalWrite(LED_PIN, LOW);

  // RECEIVER
  // In this simulation, the optical channel delivers
  // the transmitted data to the receiver.
  receivedMessage = message;

  Serial.println("--------------------------------");
  Serial.print("Receiver Output: ");
  Serial.println(receivedMessage);
  Serial.println("--------------------------------");
  Serial.println("Transmission Complete!");
  Serial.println();
  Serial.println("Enter your next message:");
}

void loop() {

  if (Serial.available()) {

    String message = Serial.readStringUntil('\n');

    message.trim();

    if (message.length() > 0) {
      sendMessage(message);
    }
  }
}