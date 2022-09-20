class Motor
{
public:
  int Motor_EnPin;
  int Motor_StpPin;
  int Motor_DirPin;
  void Motor_Init();
  Motor(int En,int Sto,int Dir);
  void Motor_1round(int delayms,bool Dir);
};


Motor::Motor(int En,int Stp,int Dir)
{
  this->Motor_DirPin=Dir;
  this->Motor_EnPin=En;
  this->Motor_StpPin=Stp;
}

void Motor::Motor_Init()
{
  pinMode(this->Motor_DirPin , OUTPUT);  digitalWrite(this->Motor_DirPin , LOW);  // initialize the Emm42_En_Pin as an output
  pinMode(this->Motor_StpPin, OUTPUT);  digitalWrite(this->Motor_StpPin, LOW);  // initialize the Emm42_Stp_Pin as an output
  pinMode(this->Motor_EnPin, OUTPUT);  digitalWrite(this->Motor_EnPin, LOW);  // initialize the Emm42_Dir_Pin as an output
}

void Motor::Motor_1round(int delayms,bool dir)//dir 0顺时针
{
   int i = 0;
   digitalWrite(this->Motor_DirPin,dir);
  for(i=0;i<=6400;i++)
  {
    delayMicroseconds(delayms);
    digitalWrite(this->Motor_StpPin, !digitalRead(this->Motor_StpPin));
  }
}
