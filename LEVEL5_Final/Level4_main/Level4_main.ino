//Arduino Uno
#include <Wire.h>
#include <avr/wdt.h>

uint32_t Data = 0;
/*-----------------------------------------------*/
void setup() {
  Serial.begin(9600); //set the baud rate for serial communication
  NeopixelSetup();
  ServoSetup();
  ServoHome();
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Serial.println("Level 4");
  Serial.println("FWV 1.0.0");
  LcdSetup();
}
/*-----------------------------------------------*/
void loop() {
  if (Serial.available() > 0) {
    int newData = Serial.parseInt();
    if (newData != 0) {
      Data = newData;
    }
  }
  switch (Data) {
    case 1:
        DisplayLcd(2, "Robot  Dance", 0, "");
        LiftRightHand();
        LiftLeftHand();
        HeadShake(130, 70, 5);
        BeginRightHand(); 
        BeginLeftHand();
      break;

    case 2:
      DisplayLcd(3, "Hand Gripe", 0, "");
      HandRightGripe();
      HandLeftGripe();
      break;

    case 3:
      DisplayLcd(2, "Hand Release", 0, "");
      HandRightRelease();
      HandLeftRelease();
      break;

    case 4:
      DisplayLcd(3, "Color Wipe", 0, "");
      ColorWipe(255,50);
      NeopixelClose();
      break;
    
    case 5:
      DisplayLcd(2, "RedEye Blink", 0, ""); //Red eye blink
      Color(255, 0, 0);
      delay(500);
      NeopixelClose();
      break;

    case 6:
      DisplayLcd(4, "Rainbow", 0, "");
      Rainbow(50);
      break;

    case 7:
      break;
    
    case 8://Stop
      DisplayLcd(6, "STOP", 0, "");
      ServoStop();
      NeopixelClose();
      break;

    case 9://Reset
      DisplayLcd(5, "RESET", 0, "");
      resetFunc();
      break;         

    case 13: //GrapDetectmove
    DisplayLcd(4, "Grap Move",0, "");
    LiftRightHand();
    LiftLeftHand();
    delay(750);
    Color(0, 0, 255);
    HandRightGripe();
    HandLeftGripe();
    break;

  }
}

void resetFunc() { // Restart
  wdt_disable();
  wdt_enable(WDTO_15MS);
  while (1) {}
}
