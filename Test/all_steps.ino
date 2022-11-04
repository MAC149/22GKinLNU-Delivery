//需现场调节灰度，根据避障效果调节1、2、3处。

//避障记录
int j = 0;

#define   angle_90    1.4
#define   angle_180   2.8

#define   mpujz_0     0.0
#define   mpujz_l90   90.0
#define   mpujz_r90   -90.0
#define   mpujz_180   180.0


extern char uart_recv[64];

//**********************************************************************************************************第一步
void step_first()
{
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_6x13_tf); // choose a suitable font
  u8g2.drawStr(10,15,"0.0g");  // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  //*****************************************************直走
  //*****************************************************扫码
  QRcode_scan();
  //*****************************************************开关盒子 + 超声波检测
  switch (QRcode[0])
  {
    case '1': {
        speech2();//扫描完成，请装入一号物料，并关闭仓门(5.3秒左右)      
        Servo1_Writes(servo_1_open, servo_delay);
        delay(4300);
        while(sonar_Cheek(1));
        //speech10();//仓门即将关闭（2.5秒左右）                        
        //delay(2500);
        while(sonar_Cheek(1));
        //speech4();//一号仓门已关闭（2.3秒左右）
        Servo1_Writes(servo_1_close, servo_delay);                     
        //delay(2300);
        u8g2.clearBuffer();
        u8g2.drawStr(10,15,"27.8g");  // write something to the internal memory
        u8g2.sendBuffer();          // transfer internal memory to the display
        break;
      }
    case '2': {
        speech3();//扫描完成，请装入二号物料，并关闭仓门(5.3秒左右)
        Servo2_Writes(servo_2_open, servo_delay);      
        delay(5300);
        while(sonar_Cheek(2));
        //speech10();//仓门即将关闭（2.5秒左右）                        
        //delay(2500);
        while(sonar_Cheek(2));
        //speech5();//二号仓门已关闭（2.3秒左右）                
        Servo2_Writes(servo_2_close, servo_delay);     
        //delay(2300);;
        break;
      }
  }
  forward(1, Emm42_delay);
  //*****************************************************红外避障
  for (int i = 0; i < 12; i++) {
    forward(0.25, Emm42_delay);
    while (!digitalRead(hw_b)) {
      delay(100);
      while (!digitalRead(hw_b)) {
        left(0.2, Emm42_delay);               //1调
        j++;
        break;
      }
    }
    if (j != 0 || (i + 1) % 4 == 0) {
      adjust_angle(mpujz_0);
    }
  }


  
  for(int i = 0; i < 3; i++){
    forward(1.45, Emm42_delay);
    adjust_angle(mpujz_0);
  }
  //*****************************************************mv识别红绿灯
  do {
    delay(200);
    uart_recv[0]=='a';
    Get_message('S');
  } while (uart_recv[0] != 'G');
  forward(1.9, 50);
}
//**********************************************************************************************************第二步
void step_second()
{
  //*****************************************************第一次转弯并回头放东西
  switch (QRcode[1])
  {
    case '1': {
        turn_left(angle_90, Emm42_delay);
        adjust_angle(mpujz_l90);
        forward(2.3, Emm42_delay);
        adjust_angle(mpujz_l90);
        forward(2.4, Emm42_delay);
        forward_right(1, Emm42_delay);
        adjust_angle(mpujz_l90);
        speech6();//到达一号收货点，请出示提货码（4.1秒左右）            
        delay(4100);
        break;
      }
    case '2': {
        turn_right(angle_90, Emm42_delay);
        adjust_angle(mpujz_r90);
        forward(2.3, Emm42_delay);
        adjust_angle(mpujz_r90);
        forward(2.6, Emm42_delay);
        forward_left(1, Emm42_delay);
        adjust_angle(mpujz_r90);
        speech7();//到达二号收货点，请出示提货码（4.1秒左右）            
        delay(4100);
        break;
      }
  }
  do
  {
    QRcode1 ="";
    QRcode1 = QR_Getstring();
  } while ((QRcode1.compareTo(QRcode)));
  //*****************************************************开关盒子 + 超声波检测
  switch (QRcode[0])
  {
    case '1': {
        speech8();//请取出一号物料，并关闭仓门（3.9秒左右）             
        Servo1_Writes(servo_1_open, servo_delay);
        delay(3900);
        while(!sonar_Cheek(1));
        //speech10();//仓门即将关闭（2.5秒左右）                        
        //delay(2500);
        while(!sonar_Cheek(1));
        //speech4();//一号仓门已关闭（2.3秒左右）        
        Servo1_Writes(servo_1_close, servo_delay);             
        //delay(2300);
        break;
      }
    case '2': {
        speech9();//请取出二号物料，并关闭仓门（4秒左右）             
        Servo2_Writes(servo_2_open, servo_delay);
        delay(5000);
        while(!sonar_Cheek(2));
        //speech10();//仓门即将关闭（2.5秒左右）                        
        //delay(2500);
        while(!sonar_Cheek(2));
        //speech5();//二号仓门已关闭（2.3秒左右）                  
        Servo2_Writes(servo_2_close, servo_delay);   
        //delay(2300);
        break;
      }
  }
}

//**********************************************************************************************************第三步
void step_third()
{
  //*****************************************************倒退并转弯
  switch (QRcode[1])
  {
    case '1': {
        back_left(1, Emm42_delay);
        back(2.3, Emm42_delay);
        adjust_angle(mpujz_l90);
        back(2.35, Emm42_delay);                           //2调
        turn_left(angle_90, Emm42_delay);
        break;
      }
    case '2': {
        back_right(1, Emm42_delay);
        back(2.3, Emm42_delay);
        adjust_angle(mpujz_r90);
        back(2.6, Emm42_delay);
        turn_right(angle_90, Emm42_delay);
        break;
      }
  }
  adjust_angle(mpujz_180);
}
//**********************************************************************************************************第四步
void step_fourth()
{
  //*****************************************************直走回来
  //  adjust_deviate();
  for (int i = 0; i < 4; i++) {
    forward(2.5, Emm42_delay);
    adjust_angle(mpujz_180);
  }
  switch (QRcode[1])
  {
      case '1': {
        for(int i = 0; i < j; i++){
          forward_left(0.55, Emm42_delay);
        }
        for(int i = 2 - i; i > 0; i--){
          forward(0.3, Emm42_delay);
        }
        break;
      }
      case '2': {
        for(int i = 0; i < j; i++){
          forward_left(0.5, Emm42_delay);
        }    
        for(int i = 2 - i; i > 0; i--){
          forward(0.3, Emm42_delay);
        }             
        break;
      }
  }
  
}
