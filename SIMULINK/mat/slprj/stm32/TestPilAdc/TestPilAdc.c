/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestPilAdc.c
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
#include "rtwtypes.h"
#include "look1_iflf_binlxpw.h"
#include "TestPilAdc_private.h"

MdlrefDW_TestPilAdc TestPilAdc_MdlrefDW;

/* Block signals (default storage) */
B_TestPilAdc_c TestPilAdc_B;

/* Output and update for referenced model: 'TestPilAdc' */
void TestPilAdcTID0(void)
{
}

/* Output and update for referenced model: 'TestPilAdc' */
void TestPilAdcTID1(real32_T *rty_Vout)
{
  {
    uint16_t i;

    /* Read regular ADC3 value */
    for (i=0; i<1; i++) {
      if (HAL_ADC_PollForConversion(&hadc3, G_ADC3_PollTimeOut) == HAL_OK) {
        ADC3_RegularConvertedValue[i] = (uint16_t)HAL_ADC_GetValue(&hadc3);
      }
    }
  }

  /* Get regular rank1 output value from ADC3 regular value buffer */
  TestPilAdc_B.ADC_Read = ADC3_RegularConvertedValue[0];

  /* Re-Start ADC3 conversion */
  HAL_ADC_Start(&hadc3);
  *rty_Vout = look1_iflf_binlxpw(TestPilAdc_B.ADC_Read,
    rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData, 4095U);
}

/* Model initialize function */
void TestPilAdc_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TestPilAdc *const TestPilAdc_M = &(TestPilAdc_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(TestPilAdc_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) &TestPilAdc_B), 0,
                sizeof(B_TestPilAdc_c));

  {
    /* user code (Initialize function Header) */
    {
      /* ADC3 initialization. */
      /* Store ADC3 informations and its handler. */
      G_ADC_Conf = &ADC3_Conf;
      G_ADC_Handler = &hadc3;
      ADC3_Conf.regularBuffer = ADC3_RegularConvertedValue;
      ADC3_Conf.regularCount = 1;
    }

    /* user code (Initialize function Body) */
    {
      /* ADC3 Start. */
      /* Start ADC3 conversion. */
      HAL_ADC_Start(&hadc3);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] TestPilAdc.c
 */
