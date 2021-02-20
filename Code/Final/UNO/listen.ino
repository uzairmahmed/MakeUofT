#include <SoftwareSerial.h>

SoftwareSerial esp32(8, 12); // RX, TX


int incoming;    // for incoming serial data

void listenSetup() {
  esp32.begin(9600);
}

void listenLoop() {
  if (esp32.available() > 0) {
    incoming = esp32.read();
    Serial.println(incoming);
    if (incoming == 49){
      cur_mode = 1;
    } else if (incoming == 50) {
      cur_mode = 2;
      sendInt(23.4);
    } else if (incoming == 51) {
      cur_mode = 3;
    } else{
      sendInt(2.4);
      cur_mode = 0;
    }
  }
}

void sendInt(float val){
  esp32.write(val);
}
