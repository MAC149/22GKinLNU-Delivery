//调整角度
void adjust_angle(double jz){
  double i[5];
  if(jz == 180.0){
    i[0] = -jz;
  }
  else{
    i[0] = jz;
  }
  if(jz == -180.0){
    i[1] = -jz;
  }
  else{
    i[1] = jz;
  }
  if(jz == 180 || jz == -180){
    while(1){
      i[2] = (mpu6050() + mpu6050()+ mpu6050()) / 3.0;
      if((i[2] > i[0] + 0.5)&&(i[2] < 0)){
        turn_right(0.005, Emm42_delay);
        //u8g2.drawStr(0,40,ecvt()
      }
      else if((i[2] < i[1] - 0.5)&&(i[2] >= 0)){
        turn_left(0.005, Emm42_delay);
      }
      else
        break;
    }
  }
  else{
    while(1){
    i[2] = (mpu6050() + mpu6050()+ mpu6050()) / 3.0;
    if(i[2] > i[0] + 0.5){
      turn_right(0.005, Emm42_delay);
      //u8g2.drawStr(0,40,ecvt()
    }
    else if(i[2] < i[1] - 0.5){
      turn_left(0.005, Emm42_delay);
    }
    else
      break;
    }
  } 
}
