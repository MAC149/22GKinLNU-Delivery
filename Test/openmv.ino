
char uart_recv[64]="a";     // 串口缓存数据
int Light_Flag=0;

void Uart_send_openmv(char CMD)  
{
  //Serial1.listen();
  switch(CMD){
    case '1':
    Serial3.print("ST"); 
    //Serial.println("Send to openmv: START");
    break;

    case '0':
    Serial3.print("ED"); 
    Serial.println("Send to openmv:END");
    break;
    
    default :
    //Serial.println("Wrong cmd to send.");
    break;
  }
  }


void Uart_recv_openmv()   
{
  if(Serial3.available()>0)
  {
   int i=0;
   while(Serial3.available()>0)
  {
    uart_recv[i]=Serial3.read();
    if(uart_recv[i]=='b'){break;}
    i++;
    delay(2);   // 延时3ms
   }
   
   if(uart_recv[0]=='R')    
   {
    
    
    Serial.println("RED LIGHT!");
     Light_Flag=0;
    }


    if(uart_recv[0]=='G' )  
    {
    
    Serial.println("GREEN LIGHT!");
    Light_Flag=1;
      }

     // 输出接收到的数据
     Serial.println(uart_recv);
     //Serial.println("1");
       } 
  }


void Get_message(char task)
{
  switch(task)
  {
    case 'S':
    Uart_send_openmv('1');
    while(uart_recv[0]=='a')
    {
        Uart_recv_openmv();
    }
    Serial.println("START");
    break;

    case 'E':
    Uart_send_openmv('1');
    while(uart_recv[0]=='a')
    {
        Uart_recv_openmv();
    }
    Serial.println("END");

    default : 
    break;
  }
  }
