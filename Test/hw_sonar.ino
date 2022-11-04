/* 红外检测： 
 * 有 -- 0
 * 无 -- 1
*/

void hw_Init()
{
  pinMode(hw_a, INPUT);
  pinMode(hw_b, INPUT);

}


/* 没有(检测到墙壁) -- 1 
 * 否则(有东西) -- 0
*/

//超声波检测
int sonar_Cheek(int sonar)
{
  int i = 1;
  switch (sonar) {
    case 1: {
        dis = 0;
        for (int i = 0; i < 15; i++) {
          dis += sonar1.Sonar_Getdis();
          delay(10);
        }
        dis = dis / 15;
        //平均约70-73
        Serial.println(dis);
        
        if (dis > 68 && dis < 76) {
          return i = 1;
        }
        else {
          return i = 0;
        }
      }
    case 2: {
        dis = 0;
        for (int i = 0; i < 15; i++) {
          dis += sonar2.Sonar_Getdis();
          delay(10);
        }
        dis = dis / 15;
        //平均约77
        if (dis > 74 && dis < 80) {
          return i = 1;
        }
        else {
          return i = 0;
        }
      }
  }

}
