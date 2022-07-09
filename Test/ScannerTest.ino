#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

String Scan_QR()
{
  unsigned long starttime;
  String str = "";
  unsigned char Wakecmd[9] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x02, 0x01, 0xAB, 0xCD};
  mySerial.write(Wakecmd, 9);
  //等待回收信号结束
  while (mySerial.read() != 0x31);
  starttime = millis();
  while (true)
  {
    //扫码模块扫出来是会加换行符的
    str = mySerial.readStringUntil('/r');
    if ((str.length() >= 1) || (millis() - starttime > 5000))
      break;
  }
  return str;
}


String qr_code = "";
void setup() {

  Serial.begin(115200);

  mySerial.begin(9600);
  
}



void loop() {
  delay(3000);
  qr_code = Scan_QR();
  Serial.println(qr_code);
}
