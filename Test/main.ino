#include <SPI.h>
#include <U8g2lib.h>
#include <Servo.h>
#include <SoftwareSerial.h>

U8G2_SH1106_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0,10,11);


void setup() {
Serial.begin(115200);

  
}

//扫码,语音播报
//舵机开门
//前进--避障--等红绿灯
//判断左右转
//转弯前进
//靠岸开舵机+语音播报
//返程
