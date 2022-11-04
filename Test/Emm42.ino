/* Dir:
 * a(LOW前进)    c(HIGH前进)
 * b(LOW前进)    d(HIGH前进)
*/
void Emm42_Init(){
  pinMode(En_a , OUTPUT);  digitalWrite(En_a , LOW);
  pinMode(Stp_a, OUTPUT);  digitalWrite(Stp_a, LOW);
  pinMode(Dir_a, OUTPUT);  digitalWrite(Dir_a, LOW);
  pinMode(En_b , OUTPUT);  digitalWrite(En_b , LOW);
  pinMode(Stp_b, OUTPUT);  digitalWrite(Stp_b, LOW);
  pinMode(Dir_b, OUTPUT);  digitalWrite(Dir_b, LOW);
  pinMode(En_c , OUTPUT);  digitalWrite(En_c , LOW);
  pinMode(Stp_c, OUTPUT);  digitalWrite(Stp_c, LOW);
  pinMode(Dir_c, OUTPUT);  digitalWrite(Dir_c, LOW);
  pinMode(En_d , OUTPUT);  digitalWrite(En_d , LOW);
  pinMode(Stp_d, OUTPUT);  digitalWrite(Stp_d, LOW);
  pinMode(Dir_d, OUTPUT);  digitalWrite(Dir_d, LOW);
}
//启动
void start_c(){
  digitalWrite(En_a, HIGH);
  digitalWrite(En_b, HIGH);
  digitalWrite(En_c, HIGH);
  digitalWrite(En_d, HIGH);
}
//停止
void stop_c(){
  digitalWrite(En_a, LOW);
  digitalWrite(En_b, LOW);
  digitalWrite(En_c, LOW);
  digitalWrite(En_d, LOW);
}
//前进
void forward(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, LOW);
  digitalWrite(Dir_b, HIGH);
  digitalWrite(Dir_c, LOW);
  digitalWrite(Dir_d, HIGH);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//右前
void forward_right(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, LOW);
  digitalWrite(En_b, LOW);
  digitalWrite(En_c, LOW);
  digitalWrite(Dir_d, HIGH);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time/2);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time/2);
    digitalWrite(Stp_a, HIGH);
    delayMicroseconds(delay_time/2+delay_time/10);
    digitalWrite(Stp_a, LOW);
    delayMicroseconds(delay_time/2+delay_time/10);
  }
}
//左前
void forward_left(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(En_a, LOW);
  digitalWrite(Dir_b, HIGH);
  digitalWrite(Dir_c, LOW);
  digitalWrite(En_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_c, HIGH);
    delayMicroseconds(delay_time/2);
    digitalWrite(Stp_c, LOW);
    delayMicroseconds(delay_time/2);
    digitalWrite(Stp_b, HIGH);
    delayMicroseconds(delay_time/2+delay_time/10);
    digitalWrite(Stp_b, LOW);
    delayMicroseconds(delay_time/2+delay_time/10);
  }
}
//后退
void back(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, HIGH);
  digitalWrite(Dir_b, LOW);
  digitalWrite(Dir_c, HIGH);
  digitalWrite(Dir_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//右后
void back_right(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(En_a, LOW);
  digitalWrite(Dir_b, LOW);
  digitalWrite(Dir_c, HIGH);
  digitalWrite(En_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    delayMicroseconds(delay_time);
  }
}
//左后
void back_left(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, HIGH);
  digitalWrite(En_b, LOW);
  digitalWrite(En_c, LOW);
  digitalWrite(Dir_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//右
void right(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, LOW);
  digitalWrite(Dir_b, LOW);
  digitalWrite(Dir_c, HIGH);
  digitalWrite(Dir_d, HIGH);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//左
void left(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, HIGH);
  digitalWrite(Dir_b, HIGH);
  digitalWrite(Dir_c, LOW);
  digitalWrite(Dir_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//左转
void turn_left(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, HIGH);
  digitalWrite(Dir_b, HIGH);
  digitalWrite(Dir_c, HIGH);
  digitalWrite(Dir_d, HIGH);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
//右转
void turn_right(float rounds, int delay_time){
  int j = 3200 * rounds;
  digitalWrite(Dir_a, LOW);
  digitalWrite(Dir_b, LOW);
  digitalWrite(Dir_c, LOW);
  digitalWrite(Dir_d, LOW);
  for (int i = 0; i < j; i++) {
    digitalWrite(Stp_a, HIGH);
    digitalWrite(Stp_b, HIGH);
    digitalWrite(Stp_c, HIGH);
    digitalWrite(Stp_d, HIGH);
    delayMicroseconds(delay_time);
    digitalWrite(Stp_a, LOW);
    digitalWrite(Stp_b, LOW);
    digitalWrite(Stp_c, LOW);
    digitalWrite(Stp_d, LOW);
    delayMicroseconds(delay_time);
  }
}
