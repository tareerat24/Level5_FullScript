//#include <WiFi.h>
//#include <ESPmDNS.h>
//#include <WiFiUdp.h>
//#include <ArduinoOTA.h>


#define LOW_SPEED 125
#define MAX_SPEED 255

uint32_t Data = 0;
long MeasureDistance = 0;
uint8_t LdrMapped = 0;
float Temp = 0;
float Humid = 0;
/*-----------------------------------------------*/
void setup() {
  //setupOTA();
  Serial.begin(9600);
  SensorAndLedSetup();
  MotorDriveSetup();
  //Serial.println("Level1-2");
  Welcome();

}
/*-----------------------------------------------*/
void loop() {
  //ArduinoOTA.handle();
  if (Serial.available() > 0) {
    int newData = Serial.parseInt();
    if (newData != 0) {
      Data = newData;
    }
  }
  switch (Data) {
    case 1:  //Display Sensor
      Dht();
      delay(1000);
      Ldr();
      delay(1000);
      Ultrasonic();
      delay(1000);
      break;

    case 2:  //Autocar
      ForwardToWall(MAX_SPEED,20);
      DisplayLcd(0, "Detect obstacles", 0, "");
      Backward(LOW_SPEED);
      delay(500);
      RotateRight(LOW_SPEED);
      delay(500);
      break;
    
    case 3:  //Eye Color Environment current not use
      break;
      
    case 4:  //Speak
      BuzzerOn();
      delay(500);
      BuzzerOff();
      delay(100);
      BuzzerOn();
      delay(200);
      BuzzerOff();
      delay(100);
      BuzzerOn();
      delay(200);
      BuzzerOff();
      break;

    case 5: //Car is a Triangle
      DisplayLcd(0, "Car's a triangle", 0, "");
      SlideRightForward(MAX_SPEED);
      delay(2000);
      SlideRightBackward(MAX_SPEED);
      delay(2000);
      SlideLeft(MAX_SPEED);
      delay(2000);
      break;

    case 6: //Car is a Rectangle
      DisplayLcd(0, "Car's Rectangle", 0, "");
      Forward(LOW_SPEED);
      delay(2000);
      SlideRight(MAX_SPEED);
      delay(2000);
      Backward(LOW_SPEED);
      delay(2000);
      SlideLeft(MAX_SPEED);
      delay(2000);
      break;

    case 7: //Flashlight
      DisplayLcd(1, "Flashlight ON", 0, "");
      FrontLedOn();
      break;

    case 8://Stop
      DisplayOff();
      BuzzerOff();
      Stop();
      FrontLedOff();
      break;

    case 9://Reset
      ESP.restart();
      break;
      
    
    case 10:   //Grapdetectmove
    break; 
  }
}
void LightStop()
{
  Ldr();
  if(LdrMapped < 15)
  {
    Data = 8;
  }
}
void ForwardToWall(uint32_t Speed, uint32_t Distance)
{
  int i = 1;
  do
  {
    Ultrasonic();
    if((MeasureDistance < Distance) && (MeasureDistance > 0))
    {
      Stop();
      delay(10);
      i--;
    }
    else
    {
      DisplayLcd(4, "Auto Car", 0, "");
      Forward(Speed);
      LightStop();
    }
  }while(i);
}