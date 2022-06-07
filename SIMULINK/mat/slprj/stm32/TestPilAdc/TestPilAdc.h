/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestPilAdc.h
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

#ifndef RTW_HEADER_TestPilAdc_h_
#define RTW_HEADER_TestPilAdc_h_
#ifndef TestPilAdc_COMMON_INCLUDES_
#define TestPilAdc_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TestPilAdc_COMMON_INCLUDES_ */

#include "STM32_Config.h"
#include "TestPilAdc_External_Functions.h"
#include "TestPilAdc_ADC.h"
#include "TestPilAdc_types.h"
#include <string.h>

/* Block signals for model 'TestPilAdc' */
#ifndef TestPilAdc_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T ADC_Read;                   /* '<Root>/ADC_Read' */
} B_TestPilAdc_c;

#endif                                 /*TestPilAdc_MDLREF_HIDE_CHILD_*/

#ifndef TestPilAdc_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_TestPilAdc {
  const char_T **errorStatus;
};

#endif                                 /*TestPilAdc_MDLREF_HIDE_CHILD_*/

#ifndef TestPilAdc_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_TestPilAdc rtm;
} MdlrefDW_TestPilAdc;

#endif                                 /*TestPilAdc_MDLREF_HIDE_CHILD_*/

extern void TestPilAdcTID0(void);
extern void TestPilAdcTID1(real32_T *rty_Vout);

/* Model reference registration function */
extern void TestPilAdc_initialize(const char_T **rt_errorStatus);

#ifndef TestPilAdc_MDLREF_HIDE_CHILD_

extern MdlrefDW_TestPilAdc TestPilAdc_MdlrefDW;

#endif                                 /*TestPilAdc_MDLREF_HIDE_CHILD_*/

#ifndef TestPilAdc_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_TestPilAdc_c TestPilAdc_B;

#endif                                 /*TestPilAdc_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestPilAdc'
 * '<S1>'   : 'TestPilAdc/Environment Controller'
 */
#endif                                 /* RTW_HEADER_TestPilAdc_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] TestPilAdc.h
 */
