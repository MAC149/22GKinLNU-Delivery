#include <Arduino.h>

//#include <MUIU8g2.h>

//#include <U8x8lib.h>
//#include <avr/pgmspace.h>

//U8G2_SH1106_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0,iSCL,iSDA);
//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 10, /* data=*/ 11, /* reset=*/ U8X8_PIN_NONE);   // 设置D10做SCL，D11做SDA，可以改为其它接口
void OLED_init(int iSCL,int iSDA)
{
  u8g2.begin();
  u8g2.enableUTF8Print();
}

void OLED_Showstring13(int pox,int poy,String a)
{
    u8g2.clearBuffer(); 
    u8g2.setFont(u8g2_font_6x13_tf);
    u8g2.drawStr(pox,poy,"aaa");
    u8g2.sendBuffer();
}
