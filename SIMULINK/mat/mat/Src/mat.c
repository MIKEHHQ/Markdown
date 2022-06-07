/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mat.c
 *
 * Code generated for Simulink model :mat.
 *
 * Model version      : 1.23
 * Simulink Coder version    : 9.7 (R2022a) 13-Nov-2021
 * TLC version       : 9.7 (Apr  7 2022)
 * C/C++ source code generated on  : Tue Jun  7 20:13:06 2022
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "mat.h"
#include "rtwtypes.h"

/* GPIOH output mask value definition. */
uint16_t GPIOH_maskWrite;

/* Block signals (default storage) */
B_mat mat_B;

/* Real-time model */
static RT_MODEL_mat mat_M_;
RT_MODEL_mat *const mat_M = &mat_M_;

/* Model step function */
void mat_step(void)
{
  {
    if (USART1_RxConf.rxStatus == SERIAL_RX_OFF) {
      USART1_RxConf.pRX_R = USART1_RxConf.pRX_BuffStart;
      mat_B.USART_Receive_o1 = 0;
      USART1_RxConf.rxStatus = SERIAL_RX_ON;

      /* USART1 interrupt receive mode. */
      HAL_UART_Receive_IT(&huart1, USART1_RxConf.pRX_BuffStart, 1.0);
    }

    /* Some data are available, copy them on output of Simulink block. */
    if (USART1_RxConf.rxStatus == SERIAL_RX_OK) {
      uint16_T idx;
      mat_B.USART_Receive_o1 = 1.0;
      mat_B.USART_Receive_o2 = (uint32_T)USART1_RxConf.pRX_R;
      for (idx = 0; idx < 1.0; idx++) {
        *(char*)(&mat_B.USART_Receive_o3[0]+idx) = *(char*)USART1_RxConf.pRX_R++;
      }

      *USART1_RxConf.pRX_R = 0;
      USART1_RxConf.rxStatus = SERIAL_RX_OFF;
    }
  }

  mat_B.led1 = 1.0 - (real_T)(mat_B.USART_Receive_o3[0] == 49);
  mat_B.led2 = 1.0 - (real_T)(mat_B.USART_Receive_o3[0] == 50);

  {
    /* Set GPIOH output mask value. */
    GPIOH_maskWrite = GPIOH->ODR;
    GPIOH_maskWrite &= 0xF3FF ;
    GPIOH_maskWrite |= (uint16_t)mat_B.led1 << 10;
    GPIOH_maskWrite |= (uint16_t)mat_B.led2 << 11;

    /* Write GPIOH input value */
    GPIOH->ODR = (uint16_t)GPIOH_maskWrite;
  }

  {
    if (mat_B.USART_Receive_o1 != 0) {
      /* Copy data to send. */
      TX_CopyData(&USART1_TxConf, (uint8_t*)mat_B.USART_Receive_o2, (uint16_t)
                  mat_B.USART_Receive_o1);
    }

    if (USART1_TxConf.nb2Send) {
      mat_B.USART_Send = 0;
      USART1_TX_SendData(&USART1_TxConf);
    }

    if (USART1_TxConf.txStatus != SERIAL_TX_ON) {
      mat_B.USART_Send = USART1_TxConf.nbSent;
    }
  }
}

/* Model initialize function */
void mat_initialize(void)
{
  /* user code (Start function Body) */

  /* USART1 initialization for receive. */
  USART1_Rx_Initialization();

  /* USART1 initialization for send. */
  USART1_Tx_Initialization();
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] mat.c
 */
