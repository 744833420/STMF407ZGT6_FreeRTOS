#include"sys.h"
int main(void)
{
	u32 t=0;
    u8 len;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	uart_init(115200);
	delay_init(84);
	LED_Init();
  while(1){
      if(USART_RX_STA&0x8000)
      {
          len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
          printf("\r\n�����͵���ϢΪ:\r\n");
          for(t=0;t<len;t++)
          {
              USART_SendData(USART1, USART_RX_BUF[t]);         //�򴮿�1��������
              while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
          }
          printf("\r\n\r\n");//���뻻��
          USART_RX_STA=0;
      }
        printf("%s\r\n",USART_RX_BUF);
        PFout(9)=!PFout(9);
        PFout(10)=!PFout(10);
		delay_ms(5000);
		t++;
        printf("�������������\r\n");
        //scanf("%d",&t);
	}
}

