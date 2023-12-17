#include "sys.h"


static TaskHandle_t app_task1_handle = NULL;

/* 任务1 */
static void app_task1(void* pvParameters);


int main(void)
{


    LED_Init();

    /* 创建app_task1任务 */
    xTaskCreate((TaskFunction_t )app_task1,  		/* 任务入口函数 */
                (const char*    )"app_task1",			/* 任务名字 */
                (uint16_t       )512,  				/* 任务栈大小 */
                (void*          )NULL,				/* 任务入口函数参数 */
                (UBaseType_t    )4, 					/* 任务的优先级 */
                (TaskHandle_t*  )&app_task1_handle);	/* 任务控制块指针 */



    /* 开启任务调度 */
    vTaskStartScheduler();

}

static void app_task1(void* pvParameters)
{
    for(;;)
    {

        GPIO_ToggleBits(GPIOF, GPIO_Pin_9);
        GPIO_ToggleBits(GPIOF, GPIO_Pin_10);
        vTaskDelay(1000);

    }
}

