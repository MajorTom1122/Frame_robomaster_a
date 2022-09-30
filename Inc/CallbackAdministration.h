#ifndef __ITTASK_H__
#define __ITTASK_H__

#include "includes.h"
#define ONE_PULSE        (154)                           //1 ���������
#define ZERO_PULSE       (56)                           //0 ���������
#define RESET_PULSE      (300)                           //80 ��λ��ƽ���������ܵ���40��
#define LED_NUMS         (44)                            //led ����
#define LED_DATA_LEN     (24)                           //led ���ȣ�������Ҫ24���ֽ�
#define WS2812_DATA_LEN  (LED_NUMS*LED_DATA_LEN)        //ws2812������Ҫ�����鳤��
//void WS_WriteAll_RGB(uint8_t n_R,uint8_t n_G, uint8_t n_B);
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan);
#endif