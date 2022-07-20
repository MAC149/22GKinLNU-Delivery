#define   Emm42_En_Pin     5   // the number of the Emm42_En_pin
#define   Emm42_Stp_Pin    6   // the number of the Emm42_Stp_pin
#define   Emm42_Dir_Pin    7   // the number of the Emm42_Dir_pin

/**************************************************************
***  Arduino和Emm42_V4.0步进闭环的接线：
    * 1. 要先根据说明书安装好Emm42_V4.0步进闭环驱动板到电机上
    * 2. Emm42_V4.0步进闭环驱动板的V+和Gnd接7~28V供电
    * 3. Emm42_V4.0闭环驱动板第一次上电，要先点击Cal选项进行编码器校准
    * 4. Arduino的引脚5接闭环驱动的En引脚（确保闭环驱动屏幕上的En选项选择Hold或者L，默认是Hold）
    * 5. Arduino的引脚6接闭环驱动的Stp引脚
    * 6. Arduino的引脚7接闭环驱动的Dir引脚

*** 注意事项：
    * 1. 要先接好线再通电，不要带电拔插6P的端子插头！！！
    * 2. 购买了非工业套餐（不带光耦隔离）要把Arduino控制板的Gnd和Emm闭环驱动板的Gnd接在一起（共地）
    * 3. 购买了工业套餐（带光耦隔离）要把Arduino控制板的5V接到Emm闭环驱动板的Com引脚上（共阳极接法）

*** 如果你的Arduino控制板是Arduino最小系统，使用USB进行供电的话，注意上电顺序：
    * 上电时，先通闭环驱动板的7~28V供电，再通Arduino控制板的USB供电，避免一些效应造成损坏！！！
    * 断电时，先断Arduino控制板的USB供电，再断闭环驱动板的7~28V供电。
***************************************************************/

long i = 0, j = 0;  bool cntDir = false;

void setup() {
  // put your setup code here, to run once:

/**********************************************************
***  初始化板载外设
    * 1. 初始化引脚5（接到闭环驱动板的En引脚）为输出模式，输出低电平（0V）
    * 2. 初始化PA6（接到闭环驱动板的Stp引脚）为输出模式，输出低电平（0V）
    * 3. 初始化PA7（接到闭环驱动板的Dir引脚）为输出模式，输出低电平（0V）
**********************************************************/
  pinMode(Emm42_En_Pin , OUTPUT);  digitalWrite(Emm42_En_Pin , LOW);  // initialize the Emm42_En_Pin as an output
  pinMode(Emm42_Stp_Pin, OUTPUT);  digitalWrite(Emm42_Stp_Pin, LOW);  // initialize the Emm42_Stp_Pin as an output
  pinMode(Emm42_Dir_Pin, OUTPUT);  digitalWrite(Emm42_Dir_Pin, LOW);  // initialize the Emm42_Dir_Pin as an output
}

void loop() {
  // put your main code here, to run repeatedly:

/**********************************************************
***  高低电平的时间间隔，即脉冲时间的一半(控制电机转动速度)
**********************************************************/
  delayMicroseconds(600); //600us

/**********************************************************
***  取反D6（Stp引脚）
**********************************************************/
  digitalWrite(Emm42_Stp_Pin, !digitalRead(Emm42_Stp_Pin));

/**********************************************************
***  记录IO取反次数（IO取反次数 = 2倍的脉冲数）
**********************************************************/
  if(cntDir)  {--i;}  else  {++i;}

/**********************************************************
***  控制PA6（Stp引脚）取反了6400次，即发送了3200个脉冲
*** 16细分下，发送3200个脉冲电机转动一圈（1.8度电机）
*** 所以计数到6400即电机旋转了一圈后，现在开始切换方向
**********************************************************/
  if(i >= 6400)
  {
    /* 延时1秒 */
    delay(1000);
    /* 改变PA7（Dir引脚）电平，切换到逆时针方向转动 */
    digitalWrite(Emm42_Dir_Pin, HIGH);  cntDir = true;
  }
  else if(i == 0)
  {
    /* 延时1秒 */
    delay(1000);
    /* 改变PA7（Dir引脚）电平切换到顺时针方向转动 */
    digitalWrite(Emm42_Dir_Pin, LOW);  cntDir = false;
  }
}
