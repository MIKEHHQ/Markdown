/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestPilAdc_ADC.h
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

#ifndef RTW_HEADER_TestPilAdc_ADC_h_
#define RTW_HEADER_TestPilAdc_ADC_h_
#include "STM32_Config.h"
#define ADC3_DMA_BUFF_SIZE             0

/**
 * @brief  ADC information
 */
typedef struct {
  uint16_t* regularBuffer;           /*!< Regular buffer for converted value. */
  uint32_t regularCount;               /*!< Number of regular channel. */
  uint32_t regularRank;                /*!< Regular current rank. */
  uint16_t* injectedBuffer;         /*!< Injected buffer for converted value. */
  uint32_t injectedCount;              /*!< Number of injected channel. */
  uint32_t injectedRank;               /*!< Injected current rank. */
  uint32_t dmaBuffSize;                /*!< Buffer size for DMA acquisition. */
  uint8_t dmaUsed;                     /*!< DMA acquisition mode. */
  uint8_t IntEndOfAllConv;       /*!< EOS/JEOS Int at end of all conversions. */
  void (* ItEOCFcn)(void);
  void (* ItJEOCFcn)(void);
  void (* ItAWDFcn)(void);
  void (* ItOVRFcn)(void);
  void (* ItDMAFullFcn)(void);
  void (* ItDMAHalfFullFcn)(void);
} ADC_ConfTypeDef;

/* Pointer to ADC informations. */
extern ADC_ConfTypeDef* G_ADC_Conf;

/* Pointer to ADC handler. */
extern ADC_HandleTypeDef* G_ADC_Handler;

/* ADC3 handler. */
extern ADC_HandleTypeDef hadc3;

/* ADC3 Regular channel Converted value buffer */
extern uint16_t ADC3_RegularConvertedValue[1];

/* ADC3 informations. */
extern ADC_ConfTypeDef ADC3_Conf;

/* ADC3 polling timeout value. Number of Solver loop. (can be changed)*/
extern uint32_t G_ADC3_PollTimeOut;

#endif                                 /* RTW_HEADER_TestPilAdc_ADC_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] TestPilAdc_ADC.h
 */