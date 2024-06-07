#include <Servo.h>

#define SERVO_HAND_RIGHT_PIN 5
#define SERVO_HAND_LEFT_PIN 6
#define SERVO_ARM_RIGHT_PIN 10
#define SERVO_ARM_LEFT_PIN 9
#define SERVO_HEAD_PIN 11

#define SET_SERVO_HOME 0
#define SET_SERVO_ARM_LEFT_HOME 180
#define SET_SERVO_HEAD_HOME 100

Servo ServoHandRight;
Servo ServoHandLeft;
Servo ServoArmRight;
Servo ServoArmLeft;
Servo ServoHead;
/*-----------------------------------------------*/
void ServoSetup()
{
  ServoHandRight.attach(SERVO_HAND_RIGHT_PIN);
  ServoHandLeft.attach(SERVO_HAND_LEFT_PIN);
  ServoArmRight.attach(SERVO_ARM_RIGHT_PIN);
  ServoArmLeft.attach(SERVO_ARM_LEFT_PIN);
  ServoHead.attach(SERVO_HEAD_PIN);
}
/*-----------------------------------------------*/
void ServoHome()
{
  ServoHandRight.write(SET_SERVO_HOME);
  ServoHandLeft.write(SET_SERVO_HOME);
  ServoArmRight.write(SET_SERVO_HOME);
  ServoArmLeft.write(SET_SERVO_ARM_LEFT_HOME);
  ServoHead.write(SET_SERVO_HEAD_HOME);
}
void ServoStop()
{
  ServoHead.detach();
  ServoArmLeft.detach();
  ServoArmRight.detach();
  ServoHandLeft.detach();
  ServoHandRight.detach();
}
/*-----------------------------------------------*/
void BeginHead() 
{ //หันหน้าตรง   face origin
  ServoHead.attach(SERVO_HEAD_PIN);
  ServoHead.write(100);
  delay(100);
  ServoHead.detach();
}
/*-----------------------------------------------*/
void HeadShake(uint8_t x, uint8_t y, uint32_t Speed) 
{ //ส่ายหัว    turn left and turn right head input x is in the range 0-100 and input y is in the range 100-180
  ServoHead.attach(SERVO_HEAD_PIN);
  for (int pos = 100; pos <= x; pos++) {  // หมุนจาก 100 ถึง 130 องศา
    ServoHead.write(pos);  // สั่งให้ Servo หมุนไปยังตำแหน่งที่กำหนด
    delay(Speed);  // หน่วงเวลาเพื่อให้มีการหมุนช้าๆ
  }
  for (int pos = x; pos >= y; pos--) 
  {  // หมุนจาก 100 ถึง 80 องศา
    ServoHead.write(pos);  // สั่งให้ Servo หมุนไปยังตำแหน่งที่กำหนด
    delay(Speed);  // หน่วงเวลาเพื่อให้มีการหมุนช้าๆ
  }
  for (int pos = y; pos <= 100; pos++) 
  {  // หมุนจาก 80 ถึง 100 องศา
    ServoHead.write(pos);  // สั่งให้ Servo หมุนไปยังตำแหน่งที่กำหนด
    delay(Speed);  // หน่วงเวลาเพื่อให้มีการหมุนช้าๆ
  }
  ServoHead.detach();
}
/*-----------------------------------------------*/
void HeadTurnLeft(int x) 
{     //ส่ายหัว ไปทางซ้าย  x คือค่าองศา ตั้งแต่ 0-100  turn left input x is in the range 0-100
  if ( 0 <= x <= 100) {
    ServoHead.attach(SERVO_HEAD_PIN);
    ServoHead.write(x);
    delay(100);
    ServoHead.detach();
  }
}
/*-----------------------------------------------*/
void HeadTurnRight(int x) 
{  //ส่ายหัว ไปทางขวา  x คือค่าองศา ตั้งแต่ 100-180  turn Right input x is in the range 100-180
  if ( 100 <= x <= 180) 
  {
    ServoHead.attach(SERVO_HEAD_PIN);
    ServoHead.write(x);
    delay(100);
    ServoHead.detach();
  }
}
/*-----------------------------------------------*/
void LiftRightHand() 
{  //ยกมือ ขาว ขึ้น  aise Right hand
  ServoArmRight.attach(SERVO_ARM_RIGHT_PIN);
  ServoArmRight.write(45);
  delay(100);
  ServoArmRight.detach();
}
/*-----------------------------------------------*/
void LiftLeftHand() 
{          //ยกมือ ซ้าย ขึ้น  aise left hand
  ServoArmLeft.attach(SERVO_ARM_LEFT_PIN);
  ServoArmLeft.write(135); //arm right
  delay(100);
  ServoArmLeft.detach();
}
/*-----------------------------------------------*/
void BeginRightHand() 
{ // มือ ซ้าย อยู่ในท่าปกติ origin Right hand
  ServoArmRight.attach(SERVO_ARM_RIGHT_PIN);
  ServoArmRight.write(0);
  delay(100);
  ServoArmRight.detach();
}
/*-----------------------------------------------*/
void BeginLeftHand() 
{ // มือ ขวา อยู่ในท่าปกติ origin left hand
  ServoArmLeft.attach(SERVO_ARM_LEFT_PIN);
  ServoArmLeft.write(180); //arm right
  delay(100);
  ServoArmLeft.detach();
}
/*-----------------------------------------------*/
void HandRightGripe()
{
  ServoHandRight.attach(SERVO_HAND_RIGHT_PIN);
  ServoHandRight.write(35); 
  delay(100);
  ServoHandRight.detach();
}
/*-----------------------------------------------*/
void HandLeftGripe()
{
  ServoHandLeft.attach(SERVO_HAND_LEFT_PIN);
  ServoHandLeft.write(35); 
  delay(100);
  ServoHandLeft.detach();
}
/*-----------------------------------------------*/
void HandRightRelease()
{
  ServoHandRight.attach(SERVO_HAND_RIGHT_PIN);
  ServoHandRight.write(0); 
  delay(100);
  ServoHandRight.detach();
}
/*-----------------------------------------------*/
void HandLeftRelease()
{
  ServoHandLeft.attach(SERVO_HAND_LEFT_PIN);
  ServoHandLeft.write(0); 
  delay(100);
  ServoHandLeft.detach();
}
