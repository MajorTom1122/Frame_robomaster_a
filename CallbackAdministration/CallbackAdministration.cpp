#include "includes.h"

void MainControlLoop()
{
	//CAN::can1.TxHandle();
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
        CAN::can1.RxHandle();
				//rt_kprintf("Receiving\n");

}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim6.Instance) {
        MainControlLoop();
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);
			rt_kprintf("TIM6Break;\n");
    }
    if (htim->Instance == htim7.Instance) {
    }
}
