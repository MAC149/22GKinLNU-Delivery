/*
kaimen1();//打开仓门1号                                  delay(1000);
kaimen2();//打开仓门2号                                  delay(1000);
jiance1();//仓门1号状态                                  delay(1000);
jiance2();//仓门2号状态                                  delay(1000);
speech1();//你好，请扫描物流二维码(3.5秒左右)                 delay(3500);
speech2();//扫描完成，请装入一号物料，并关闭仓门(5.3秒左右)      delay(5300);
speech3();//扫描完成，请装入二号物料，并关闭仓门(5.3秒左右)      delay(5300);
speech4();//一号仓门已关闭（2.3秒左右）                     delay(2300);
speech5();//二号仓门已关闭（2.3秒左右）                     delay(2300);
speech6();//到达一号收货点，请出示提货码（4.1秒左右）            delay(4100);
speech7();//到达二号收货点，请出示提货码（4.1秒左右）            delay(4100);
speech8();//请取出一号物料，并关闭仓门（3.9秒左右）             delay(3900);
speech9();//请取出二号物料，并关闭仓门（3.9秒左右）             delay(3900);
speech10();//仓门即将关闭（2.5秒左右）                        delay(2500);
*/

//你好，请扫描物流二维码(5秒左右)//
void speech1()
{
  unsigned char i = 0;
  unsigned char head[28];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x19;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC4;
  head[6] = 0xE3;
  head[7] = 0xBA;
  head[8] = 0xC3;
  head[9] = 0xA3;
  head[10] = 0xAC;
  head[11] = 0xC7;
  head[12] = 0xEB;
  head[13] = 0xC9;
  head[14] = 0xA8;
  head[15] = 0xC3;
  head[16] = 0xE8;
  head[17] = 0xCE;
  head[18] = 0xEF;
  head[19] = 0xC1;
  head[20] = 0xF7;
  head[21] = 0xB6;
  head[22] = 0xFE;
  head[23] = 0xCE;
  head[24] = 0xAC;
  head[25] = 0xC2;
  head[26] = 0xEB;
  head[27] = 0xC6;

  for(i=0; i<28; i++)
  {
    Serial1.write(head[i]);
  }
}

//扫描完成，请装入一号物料，并关闭仓门(8秒左右)//
void speech2()
{
  unsigned char i = 0;
  unsigned char head[39]={0xFD,0x00,0x24,0x01,0x01,0xC9,0xA8,0xC3,0xE8,0xCD,0xEA,0xB3,0xC9,0x2C,0xC7,0xEB,0xD7,0xB0,0xC8,0xEB,0xD2,0xBB,0xBA,0xC5,0xCE,0xEF,0xC1,0xCF,0x2C,0xB2,0xA2,0xB9,0xD8,0xB1,0xD5,0xB2,0xD6,0xC3,0xC5};
 
  for(i=0; i<39; i++){
    Serial1.write(head[i]);
  }
}

//扫描完成，请装入二号物料，并关闭仓门(8秒左右)//
void speech3()
{
  unsigned char i = 0;
  unsigned char head[42];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x27;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC9;
  head[6] = 0xA8;
  head[7] = 0xC3;
  head[8] = 0xE8;
  head[9] = 0xCD;
  head[10] = 0xEA;
  head[11] = 0xB3;
  head[12] = 0xC9;
  head[13] = 0xA3;
  head[14] = 0xAC;
  head[15] = 0xC7;
  head[16] = 0xEB;
  head[17] = 0xD7;
  head[18] = 0xB0;
  head[19] = 0xC8;
  head[20] = 0xEB;
  head[21] = 0xB6;
  head[22] = 0xFE;
  head[23] = 0xBA;
  head[24] = 0xC5;
  head[25] = 0xCE;
  head[26] = 0xEF;
  head[27] = 0xC1;
  head[28] = 0xCF;
  head[29] = 0xA3;
  head[30] = 0xAC;
  head[31] = 0xB2;
  head[32] = 0xA2;
  head[33] = 0xB9;
  head[34] = 0xD8;
  head[35] = 0xB1;
  head[36] = 0xD5;
  head[37] = 0xB2;
  head[38] = 0xD6;
  head[39] = 0xC3;
  head[40] = 0xC5;
  head[41] = 0xCB;

  for(i=0; i<42; i++){
    Serial1.write(head[i]);
  }
}

//一号仓门已关闭（3秒左右）//
void speech4()
{
  unsigned char i = 0;
  unsigned char head[20];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x11;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xD2;
  head[6] = 0xBB;
  head[7] = 0xBA;
  head[8] = 0xC5;
  head[9] = 0xB2;
  head[10] = 0xD6;
  head[11] = 0xC3;
  head[12] = 0xC5;
  head[13] = 0xD2;
  head[14] = 0xD1;
  head[15] = 0xB9;
  head[16] = 0xD8;
  head[17] = 0xB1;
  head[18] = 0xD5;
  head[19] = 0x9F;

  for(i=0; i<20; i++){
    Serial1.write(head[i]);
  }
}

//二号仓门已关闭（3秒左右）//
void speech5(){
  unsigned char i = 0;
  unsigned char head[20];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x11;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB6;
  head[6] = 0xFE;
  head[7] = 0xBA;
  head[8] = 0xC5;
  head[9] = 0xB2;
  head[10] = 0xD6;
  head[11] = 0xC3;
  head[12] = 0xC5;
  head[13] = 0xD2;
  head[14] = 0xD1;
  head[15] = 0xB9;
  head[16] = 0xD8;
  head[17] = 0xB1;
  head[18] = 0xD5;
  head[19] = 0xBE;

  for(i=0; i<20; i++){
    Serial1.write(head[i]);
  }
}

//到达一号收货点，请出示提货码（7秒左右）//
void speech6(){
  unsigned char i = 0;
  unsigned char head[34];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x1F;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB5;
  head[6] = 0xBD;
  head[7] = 0xB4;
  head[8] = 0xEF;
  head[9] = 0xD2;
  head[10] = 0xBB;
  head[11] = 0xBA;
  head[12] = 0xC5;
  head[13] = 0xCA;
  head[14] = 0xD5;
  head[15] = 0xBB;
  head[16] = 0xF5;
  head[17] = 0xB5;
  head[18] = 0xE3;
  head[19] = 0xA3;
  head[20] = 0xAC;
  head[21] = 0xC7;
  head[22] = 0xEB;
  head[23] = 0xB3;
  head[24] = 0xF6;
  head[25] = 0xCA;
  head[26] = 0xBE;
  head[27] = 0xCC;
  head[28] = 0xE1;
  head[29] = 0xBB;
  head[30] = 0xF5;
  head[31] = 0xC2;
  head[32] = 0xEB;
  head[33] = 0xF9;

  for(i=0; i<34; i++){
    Serial1.write(head[i]);
  }
}

//到达二号收货点，请出示提货码（7秒左右）//
void speech7(){
  unsigned char i = 0;
  unsigned char head[34];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x1F;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB5;
  head[6] = 0xBD;
  head[7] = 0xB4;
  head[8] = 0xEF;
  head[9] = 0xB6;
  head[10] = 0xFE;
  head[11] = 0xBA;
  head[12] = 0xC5;
  head[13] = 0xCA;
  head[14] = 0xD5;
  head[15] = 0xBB;
  head[16] = 0xF5;
  head[17] = 0xB5;
  head[18] = 0xE3;
  head[19] = 0xA3;
  head[20] = 0xAC;
  head[21] = 0xC7;
  head[22] = 0xEB;
  head[23] = 0xB3;
  head[24] = 0xF6;
  head[25] = 0xCA;
  head[26] = 0xBE;
  head[27] = 0xCC;
  head[28] = 0xE1;
  head[29] = 0xBB;
  head[30] = 0xF5;
  head[31] = 0xC2;
  head[32] = 0xEB;
  head[33] = 0xD8;

  for(i=0; i<34; i++){
    Serial1.write(head[i]);
  }
}

//请取出一号物料，并关闭仓门（6秒左右）//
void speech8(){
  unsigned char i = 0;
  unsigned char head[32];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x1D;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC7;
  head[6] = 0xEB;
  head[7] = 0xC8;
  head[8] = 0xA1;
  head[9] = 0xB3;
  head[10] = 0xF6;
  head[11] = 0xD2;
  head[12] = 0xBB;
  head[13] = 0xBA;
  head[14] = 0xC5;
  head[15] = 0xCE;
  head[16] = 0xEF;
  head[17] = 0xC1;
  head[18] = 0xCF;
  head[19] = 0xA3;
  head[20] = 0xAC;
  head[21] = 0xB2;
  head[22] = 0xA2;
  head[23] = 0xB9;
  head[24] = 0xD8;
  head[25] = 0xB1;
  head[26] = 0xD5;
  head[27] = 0xB2;
  head[28] = 0xD6;
  head[29] = 0xC3;
  head[30] = 0xC5;
  head[31] = 0xA0;

  for(i=0; i<32; i++){
    Serial1.write(head[i]);
  }
}

//请取出二号物料，并关闭仓门（6秒左右）//
void speech9(){
  unsigned char i = 0;
  unsigned char head[32];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x1D;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC7;
  head[6] = 0xEB;
  head[7] = 0xC8;
  head[8] = 0xA1;
  head[9] = 0xB3;
  head[10] = 0xF6;
  head[11] = 0xB6;
  head[12] = 0xFE;
  head[13] = 0xBA;
  head[14] = 0xC5;
  head[15] = 0xCE;
  head[16] = 0xEF;
  head[17] = 0xC1;
  head[18] = 0xCF;
  head[19] = 0xA3;
  head[20] = 0xAC;
  head[21] = 0xB2;
  head[22] = 0xA2;
  head[23] = 0xB9;
  head[24] = 0xD8;
  head[25] = 0xB1;
  head[26] = 0xD5;
  head[27] = 0xB2;
  head[28] = 0xD6;
  head[29] = 0xC3;
  head[30] = 0xC5;
  head[31] = 0x81;

  for(i=0; i<32; i++){
    Serial1.write(head[i]);
  }
}
//仓门即将关闭（3秒左右）//
void speech10(){
  unsigned char i = 0;
  unsigned char head[17];

  head[0] = 0xFD                 ;
  head[1] = 0x00;
  head[2] = 0x0E;
  head[3] = 0x01;
  head[4] = 0x01;
  head[5] = 0xB2;
  head[6] = 0xD6;
  head[7] = 0xC3;
  head[8] = 0xC5;
  head[9] = 0xBC;
  head[10] = 0xB4;
  head[11] = 0xBD;
  head[12] = 0xAB;
  head[13] = 0xB9;
  head[14] = 0xD8;
  head[15] = 0xB1;
  head[16] = 0xD5;

  for(i=0; i<17; i++){
    Serial1.write(head[i]);
  }
}

void speakword0()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC1;
  head[6] = 0xE3;
  head[7] = 0xDB;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword1()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xD2;
  head[6] = 0xBB;
  head[7] = 0x90;
}

void speakword2()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB6;
  head[6] = 0xFE;
  head[7] = 0xB1;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword3()
{
 unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC8;
  head[6] = 0xFD;
  head[7] = 0xCC;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword4()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xCB;
  head[6] = 0xC4;
  head[7] = 0xF6;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword5()
{
   unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xCE;
  head[6] = 0xE5;
  head[7] = 0xD2;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword6()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC1;
  head[6] = 0xF9;
  head[7] = 0xC1;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword7()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xC6;
  head[6] = 0xDF;
  head[7] = 0xE0;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword8()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB0;
  head[6] = 0xCB;
  head[7] = 0x82;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword9()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xBE;
  head[6] = 0xC5;
  head[7] = 0x82;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakword10()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xCA;
  head[6] = 0xAE;
  head[7] = 0x9D;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakwordpoint()
{
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB5;
  head[6] = 0xE3;
  head[7] = 0xAF;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void speakwordhud(){
  unsigned char i = 0;
  unsigned char head[8];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x05;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xB0;
  head[6] = 0xD9;
  head[7] = 0x90;

  for(i=0; i<8; i++){
    Serial.write(head[i]);
  }
}

void fake1(){
  unsigned char i = 0;
  unsigned char head[18];

  head[0] = 0xFD;
  head[1] = 0x00;
  head[2] = 0x0F;
  head[3] = 0x01;
  head[4] = 0x00;
  head[5] = 0xCB;
  head[6] = 0xC4;
  head[7] = 0xCA;
  head[8] = 0xAE;
  head[9] = 0xBE;
  head[10] = 0xC5;
  head[11] = 0xB5;
  head[12] = 0xE3;
  head[13] = 0xBE;
  head[14] = 0xC5;
  head[15] = 0xBF;
  head[16] = 0xCB;
  head[17] = 0xBA;

  for(i=0; i<18; i++){
    Serial1.write(head[i]);
  }
}
