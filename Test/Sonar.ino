class Sonar
{
public:
        int TrigPin;
        int EchoPin;
        void Sonar_Init();
        u8 Sonar_Getdis();
};
void Sonar::Sonar_Init()
{
    pinMode(this->TrigPin,OUTPUT);
    pinMode(this->EchoPin,INPUT);
}

u8 Sonar::Sonar_Getdis()
{
    u8 dis;
    digitalWrite(this->TrigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(this->TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(this->TrigPin,LOW);
    dis=pulseIn(this->EchoPin,HIGH)/58.0;//cm
    dis=(int(dis*100.0)/100);
    return dis;
}