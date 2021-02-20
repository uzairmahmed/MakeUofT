#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

char auth[] = "YsxVCyLo9hss6t4qg8q3H-ZwOK06OnZz";

#define RXD2 16
#define TXD2 17

int cur_mode = 0;

int value = 0;
String units = "NULL";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.println("I AM ESP32");
  
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("Blynk");
  Blynk.begin(auth); 
}

void loop() { 
Blynk.run();
  unitsManager();
  Serial2.print(cur_mode);
  if (Serial2.available()) {
    value = ((char)Serial2.read());
  }

  Blynk.virtualWrite(V0, value);
  Blynk.virtualWrite(V1, units);
}

void unitsManager(){
  if (cur_mode==0){
    units = "NULL";
  } else if (cur_mode==1){
    units = "VOLTS";
  } else if (cur_mode==2){
    units = "OHMS";
  } else if (cur_mode==3){
    units = "BEEPS";
  }
}

BLYNK_WRITE(V2) {
  switch (param.asInt())
  {
    case 1: // Item 1
      Serial.println("Voltmeter");
      cur_mode = 1;
      break;
    case 2: // Item 2
      Serial.println("Ohmmeter");
      cur_mode = 2;
      break;
    case 3: // Item 3
      Serial.println("Continuity");
      cur_mode = 3;
      break;
    default:
      Serial.println("Unknown");
      cur_mode = 0;
  }
}
