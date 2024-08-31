#include <BleKeyboard.h>

#define BUTTON_PIN 4

volatile bool triggerVolumeUp = false;

BleKeyboard bleKeyboard("Remote Shutter", "Diego Roca", 100);  // You can customize the name and manufacturer

void IRAM_ATTR takePicture() {
  if (bleKeyboard.isConnected()) {
    triggerVolumeUp = true;
  }
}

void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Set button pin as input with an internal pull-up resistor

  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), takePicture, FALLING);
  
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    
    if (triggerVolumeUp) {
      Serial.println("Sending Volume Up signal");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      delay(100);
      triggerVolumeUp = false;
    }
  }
  else {
    Serial.println("Waiting for connection...");
    delay(1000);  // General delay between loops
  }
}
