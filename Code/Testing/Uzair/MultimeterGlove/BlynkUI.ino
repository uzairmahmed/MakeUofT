//#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT

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


void BlynkSetup(){
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("Blynk");
  Blynk.begin(auth);

  
}

void BlynkManager(){
  Blynk.run();
  timer.run();
}
