/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main.c
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

/* This section of code is going to be merged by the STM32CubeMX tool. */
/* USER CODE BEGIN 0 */
/* Add include files for PIL processing. */
#include <stdio.h>
#include "xil_interface_lib.h"
#include "rtwtypes.h"
#include "STM32SerialRtiostream-ProfilerTimer.h"

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN 1 */
  XIL_INTERFACE_LIB_ERROR_CODE errorCode = XIL_INTERFACE_LIB_SUCCESS;
  int errorOccurred = 0;

  /* Avoid warnings about infinite loops */
  volatile int loop = 1;

  /* USER CODE END 1 */

  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN 2 */
  /* Profiling settings: set reload SysTick timer to max value 0x00FFFFFF */
  profileTimerInit();

  /* XIL initialization */
  const int argc = 0;
  void * argv = (void *) 0;
  errorCode = xilInit(argc, argv);
  errorOccurred = (errorCode != XIL_INTERFACE_LIB_SUCCESS);

  /* USER CODE END 2 */

  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN WHILE */
  /* main XIL loop */
  while (loop && !errorOccurred) {
    errorCode = xilRun();
    if (errorCode != XIL_INTERFACE_LIB_SUCCESS) {
      if (errorCode == XIL_INTERFACE_LIB_TERMINATE) {
        /* orderly shutdown of rtiostream */
        errorOccurred = (xilTerminateComms() != XIL_INTERFACE_LIB_SUCCESS);
      } else {
        errorOccurred = 1;
      }
    }
  }

  /* trap error with infinite loop */
  if (errorOccurred)
    while (loop) {
    }

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
  /* USER CODE END 3 */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] main.c
 */
