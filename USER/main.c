#include "sys.h"
static TaskHandle_t app_task1_handle = NULL;
/* ����1 */
static void app_task1(void* pvParameters);
int main(void)
{
    LED_Init();
    /* ����app_task1���� */
    xTaskCreate((TaskFunction_t )app_task1,  		/* ������ں��� */
                (const char*    )"app_task1",			/* �������� */
                (uint16_t       )512,  				/* ����ջ��С */
                (void*          )NULL,				/* ������ں������� */
                (UBaseType_t    )4, 					/* ��������ȼ� */
                (TaskHandle_t*  )&app_task1_handle);	/* ������ƿ�ָ�� */
    /* ����������� */
    vTaskStartScheduler();

}
static void app_task1(void* pvParameters)  //����1
{
    for(;;)
    {

        //Toggle the GPIO pins

        //Toggle the GPIO pin 9
        GPIO_ToggleBits(GPIOF, GPIO_Pin_9);
        //Toggle the GPIO pin 10
        GPIO_ToggleBits(GPIOF, GPIO_Pin_10);
        //�ӳ�1000����
        vTaskDelay(1000);

    }
}

