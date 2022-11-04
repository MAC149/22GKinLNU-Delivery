
String QR_Getstring()
{
  unsigned long starttime;
  String str = "";
  unsigned char Wakecmd[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x02, 0x01, 0xAB, 0xCD};
  Serial2.write(Wakecmd, 9);
  //等待回收信号结束
  while (Serial2.read() != 0x31);
  starttime = millis();
  while (true)
  {
    //扫码模块扫出来是会加换行符的
    str = Serial2.readStringUntil('/r');
    if ((str.length() >= 1) || (millis() - starttime > 10000))
      break;
  }
  return str;
}

//*****************************************************扫码
void QRcode_scan(){
  do
  {
    QRcode=QR_Getstring();
  }while(QRcode=="");
  //delay(1000);
}
