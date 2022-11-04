#include"Sonar.h" 
Sonar::Sonar(int trig,int echo)
{
  this->TrigPin=trig;
  this->EchoPin=echo;
}
void Sonar::Sonar_Init()
{
    pinMode(this->TrigPin,OUTPUT);
    pinMode(this->EchoPin,INPUT);
}

u8 Sonar::Sonar_Getdis()
{
    double dis;
    digitalWrite(this->TrigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(this->TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(this->TrigPin,LOW);
    dis=pulseIn(this->EchoPin,HIGH)/5.80;//cm
    //dis=(u16(dis*100.0)/100);
    return (u16)dis;
}
