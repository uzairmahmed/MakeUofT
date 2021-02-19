
#define BLYNK_PRINT Serial

#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YsxVCyLo9hss6t4qg8q3H-ZwOK06OnZz";

// Pin V0, V1 - LCD
BlynkTimer timer;
void sendSeconds() {
  Blynk.virtualWrite(V0, millis() / 1000);
}

void sendMillis() {
  Blynk.virtualWrite(V1, millis());
}

// Pin V2 - Mode Menu
BLYNK_WRITE(V2) {
  switch (param.asInt())
  {
    case 1: // Item 1
      Serial.println("Voltmeter");
      break;
    case 2: // Item 2
      Serial.println("Ohmmeter");
      break;
    case 3: // Item 3
      Serial.println("Continuity");
      break;
    default:
      Serial.println("Unknown");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("Blynk");
  Blynk.begin(auth);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSeconds);
  // Setup a function to be called every second
  timer.setInterval(1000L, sendMillis);
}

void loop()
{
  Blynk.run();
  timer.run();
}
