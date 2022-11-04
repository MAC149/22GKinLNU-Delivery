//A7不能用
//A14、A15不能用
//电机
#define   En_a     4
#define   Stp_a    3
#define   Dir_a    22
#define   En_b     7
#define   Stp_b    6
#define   Dir_b    5
#define   En_c     10
#define   Stp_c    9
#define   Dir_c    8
#define   En_d     13
#define   Stp_d    12
#define   Dir_d    11

#define   Emm42_delay   36

//红外
#define   hw_a    A9  //A7不能用
#define   hw_b    A8

//超声波
#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards
#include "Sonar.h"
Sonar sonar2(44, 45);
Sonar sonar1(40, 41);
double dis = 0;
extern char uart_recv[64];

//舵机
#include <Servo.h>
Servo servo1;
Servo servo2;
#define   servo_1_open    180
#define   servo_1_close   6
#define   servo_2_open    0
#define   servo_2_close   170
#define   servo_delay     1000

//扫码
String QRcode = "";
String QRcode1 = "";

//中断
#include <MsTimer2.h>

//语音模块
//#include <SoftwareSerial.h>
//#define yuyin_rx 52
//#define yuyin_tx 53
//SoftwareSerial yuyin(yuyin_rx, yuyin_tx); // RX, TX

//陀螺仪

//Openmv

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ A3, /* data=*/ A2, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
//#include "HX711.h"
//HX711 hx711;


void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
  //电机
  Emm42_Init();

  //超声波
  sonar1.Sonar_Init();
  sonar2.Sonar_Init();

  //红外
  pinMode(hw_a, INPUT);
  pinMode(hw_b, INPUT);
  Serial.begin(9600);

  //语音模块
  Serial1.begin(9600);

  //扫码
  Serial2.begin(9600);

  //openmv
  Serial3.begin(9600);
  
//  hx711.begin(37,39,128);
//  Serial.println("aaaaaa");
//  hx711.set_gain(128);
//  Serial.println("bbbbbbbb");
//  //hx711.tare(1);
//  Serial.println("cccccccccc");
  
  //舵机
  Servo1_Init(A4);
  Servo2_Init(A5);
  Servo1_Writes(servo_1_close, servo_delay);
  Servo2_Writes(servo_2_close, servo_delay);
  //speech1();//你好，请扫描物流二维码(3.5秒左右)                 
  //陀螺仪
  mpu_Init();
   

}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(1000);  
//  while(1){
// sonar_Cheek(1);
//}
  step_first();
  step_second();
  step_third();
  step_fourth();
//Servo1_Writes(servo_1_close, servo_delay);
//Servo2_Writes(servo_2_close, servo_delay);
//Servo1_Writes(servo_1_open, servo_delay);
//while(1){
//  sonar_Cheek(1);
//}
}
