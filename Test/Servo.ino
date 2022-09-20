#include <Servo.h>

Servo servo1;
Servo servo2;

void Servo1_Init(int dat)
{
    servo1.attach(dat);
}

void Servo2_Init(int dat)
{
    servo2.attach(dat);
}

void Servo1_Writes(int pos,int delays)//pos 0-180
{
    servo1.write(pos);
    delay(delays);
}

void Servo2_Writes(int pos,int delays)//pos 0-180
{
    servo2.write(pos);
    delay(delays);
}

void Servo1_Writems(int pos,int delayms)//pos 0-180
{
    servo1.write(pos);
    delayMicroseconds(delayms);
}

void Servo2_Writems(int pos,int delayms)//pos 0-180
{
    servo2.write(pos);
    delayMicroseconds(delayms);
}
