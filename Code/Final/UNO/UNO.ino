
int cur_mode = 0;

void setup() {
  Serial.begin(115200);
  listenSetup();
}

void loop() {
  listenLoop();
  modeManager();
}

void modeManager(){
  if (cur_mode == 1){
    calculate_voltage();
  } else if (cur_mode == 2){
    calculate_resistor();
  } else if (cur_mode == 3){
    start_piezo();
  } else{
    null_mode();
  }
}
