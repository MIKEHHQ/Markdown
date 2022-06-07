/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mat.h
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

#ifndef RTW_HEADER_mat_h_
#define RTW_HEADER_mat_h_
#ifndef mat_COMMON_INCLUDES_
#define mat_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* mat_COMMON_INCLUDES_ */

#include "STM32_Config.h"
#include "mat_External_Functions.h"
#include "mat_USART.h"
#include "mat_types.h"

/* GPIOH output mask value declaration. */
extern uint16_t GPIOH_maskWrite;

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T USART_Receive_o1;             /* '<Root>/USART_Receive' */
  real_T USART_Send;                   /* '<Root>/USART_Send' */
  real_T led1;                         /* '<Root>/MATLAB Function' */
  real_T led2;                         /* '<Root>/MATLAB Function' */
  uint32_T USART_Receive_o2;           /* '<Root>/USART_Receive' */
  uint8_T USART_Receive_o3[32];        /* '<Root>/USART_Receive' */
} B_mat;

/* Real-time Model Data Structure */
struct tag_RTM_mat {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_mat mat_B;

/* Model entry point functions */
extern void mat_initialize(void);
extern void mat_step(void);

/* Real-time Model object */
extern RT_MODEL_mat *const mat_M;

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
 * '<Root>' : 'mat'
 * '<S1>'   : 'mat/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_mat_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] mat.h
 */
