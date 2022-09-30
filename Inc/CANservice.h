#ifndef CANSERVICE_H
#define CANSERVICE_H

#include "includes.h"
class CAN
{
public:
    static CAN can1;
    HAL_StatusTypeDef RxHandle();
    HAL_StatusTypeDef TxHandle(CAN_TxHeaderTypeDef* TxHeader,uint8_t *TxMsg);
private:
		CAN();
		~CAN(){}
    uint8_t currentSendData;
    CAN_HandleTypeDef *hcan;
    CAN_RxHeaderTypeDef RxMsg;
    uint8_t *RxData;
    uint8_t *TxData;

};

#endif