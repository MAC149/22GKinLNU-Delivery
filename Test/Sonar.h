#include<Arduino.h>
class Sonar
{
public:
        int TrigPin;
        int EchoPin;
        void Sonar_Init();
        u8 Sonar_Getdis();
        Sonar(int trig,int echo);
};
