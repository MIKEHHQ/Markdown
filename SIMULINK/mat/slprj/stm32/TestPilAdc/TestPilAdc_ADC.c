/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestPilAdc_ADC.c
 *
 * Code generated for Simulink model :TestPilAdc.
 *
 * Model version      : 8.0
 * Simulink Coder version    : 9.7 (R2022a) 13-Nov-2021
 * TLC version       : 9.7 (Apr  7 2022)
 * C/C++ source code generated on  : Tue Jun  7 19:21:13 2022
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. MISRA C:2012 guidelines
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

#include "TestPilAdc.h"
#include "TestPilAdc_ADC.h"

/* Pointer to ADC informations. */
ADC_ConfTypeDef* G_ADC_Conf;

/* Pointer to ADC handler. */
ADC_HandleTypeDef* G_ADC_Handler;

/* ADC3 Regular channel Converted value buffer */
uint16_t ADC3_RegularConvertedValue[1];

/* ADC3 informations. */
ADC_ConfTypeDef ADC3_Conf = {
  /* Regular channels. */
  NULL, 0, 0,

  /* Injected channels. */
  NULL, 0, ADC_INJECTED_RANK_1,

  /* Dma. */
  0, false,

  /* End of conversion. */
  false,

  /* Interrupts callbacks. */
  NULL, NULL, NULL, NULL, NULL, NULL
};

/* ADC3 polling timeout value. Number of Solver loop. (can be changed)*/
uint32_t G_ADC3_PollTimeOut = 10;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] TestPilAdc_ADC.c
 */
