//Arduino mega
#include <avr/wdt.h>
/////
uint32_t Data = 0;

void setup() {
/*-----------------------------------------------*///Uart
  Serial.begin(9600);
  Serial1.begin(9600);//Level1-2
  Serial2.begin(9600);//Level4
  Oled1306Setup();
  Serial.println("Level 5 Ready");
  Serial.println("FWV 1.0.0");
}

void loop() {
  OLED();
}

void resetFunc() { // Restart
  wdt_disable();
  wdt_enable(WDTO_15MS);
  while (1) {}
}