#include "includes.h"
#include <rtthread.h>
CAN::CAN()
{
	 HAL_StatusTypeDef HAL_Status;

    hcan = &hcan1;
    //<CAN filter>
    CAN_FilterTypeDef sFilterConfig;

    sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    sFilterConfig.FilterIdHigh = 0x0000;
    sFilterConfig.FilterIdLow = 0x0000;
    sFilterConfig.FilterMaskIdHigh = 0x0000;
    sFilterConfig.FilterMaskIdLow = 0x0000;
    sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
    sFilterConfig.FilterActivation = ENABLE;
    sFilterConfig.FilterBank = 0;
    sFilterConfig.SlaveStartFilterBank = 0;

    HAL_CAN_ConfigFilter(hcan, &sFilterConfig);
    HAL_CAN_Start(hcan);
    HAL_CAN_ActivateNotification(hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
    HAL_Status = HAL_CAN_ActivateNotification(hcan,CAN_IT_TX_MAILBOX_EMPTY);
    if(HAL_Status != HAL_OK){
        Error_Handler();
    }

}

HAL_StatusTypeDef CAN::TxHandle(CAN_TxHeaderTypeDef* TxHeader,uint8_t *TxMsg) {
	

    //</encode data to be sent to motor>

    //<transmit>
    if (HAL_CAN_GetTxMailboxesFreeLevel(hcan) > 0) {
        if(HAL_CAN_AddTxMessage(hcan, TxHeader, TxMsg, (uint32_t *) CAN_TX_MAILBOX0)!=HAL_OK)
					Error_Handler();
    }
    //</transmit>
}


HAL_StatusTypeDef CAN::RxHandle(void) {
    HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&RxMsg,RxData);
	/*
	todo:
	use abstract product classes to deliver messages
	*/

}
CAN CAN::can1;