#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

int mode = 0;
char[][] modes = {"Voltmeter", "Ohmmeter", "Continuity"};
char[][] units = {"Volts", "Ohms", "Beep"};

void setup(){
  // Debug console
  Serial.begin(9600);
//  BlynkSetup();
IOSetup();
}

void loop(){
//  BlynkManager();
IOManager();
}
