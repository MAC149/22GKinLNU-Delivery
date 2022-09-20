
char uart_recv[64];     // 串口缓存数据


void Uart_send_openmv(char CMD)  
{
  //Serial1.listen();
  switch(CMD){
    case '1':
    Serial1.print("ST"); 
    Serial.println("Send to openmv: START");
    break;

    case '0':
    Serial1.print("ED"); 
    Serial.println("Send to openmv:END");
    break;
    
    default :
    Serial.println("Wrong cmd to send.");
    break;
  }
  }


void Uart_recv_openmv()   
{
  if(Serial1.available()>0)
  {
   int i=0;
   while(Serial1.available()>0)
  {
    uart_recv[i]=Serial1.read();
    i++;
    delay(2);   // 延时3ms
   }
   
   if(uart_recv[0]=='R')    
   {
    
    
    Serial.println("RED LIGHT!");
      
    }


    if(uart_recv[0]=='G' )  
    {
    
    Serial.println("GREEN LIGHT!");
      }

     // 输出接收到的数据
     Serial.println(uart_recv);
       } 
  }


void Get_message(char task)   // Q-二维码 P-物料位置 S-抓取顺序
{
  switch(task)
  {
    case 'S':
    Uart_send_openmv('1');  // 发送扫描二维码的指令  √
    while(uart_recv=="")
    {
        Uart_recv_openmv();
    }
    Serial.println("START");
    break;

    case 'E':
    Uart_send_openmv('1');  // 发送扫描二维码的指令  √
    while(uart_recv=="")
    {
        Uart_recv_openmv();
    }
    Serial.println("END");

    default : 
    break;
  }
  }