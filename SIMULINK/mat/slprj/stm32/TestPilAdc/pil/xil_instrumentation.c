/*
 * File: xil_instrumentation.c
 *
 * Code generated for instrumentation.
 *
 */

#include "xil_instrumentation.h"

/* Code instrumentation offset(s) for model TestPilAdc */
#define taskTimeStart_TestPilAdc_offset 0
#define taskTimeEnd_TestPilAdc_offset  0

/* A function parameter may be intentionally unused */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)
# else
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

#define SIZEOF_TIMER_TYPE              sizeof(uint32_T)

static uint32_T xsd_xil_timer_corrected = 0;
static uint32_T xsd_xil_timer_unfreeze = 0;
static uint32_T xsd_xil_freezing_busy = 0;
void xilUploadProfilingData(uint32_T sectionId)
{
  xilUploadCodeInstrData((void *)(&xsd_xil_timer_corrected), (uint32_T)
    (SIZEOF_TIMER_TYPE), sectionId);
}

/* The internal freeze and unfreeze methods cannot be nested. The customer-visible implementation avoids nesting problems */
void xilProfilingTimerFreezeInternal(void)
{
  /* Update the value of the corrected timer to exclude time spent in the
   * instrumentation code.
   *
   * Using a timer that decrements on each tick.
   */
  xsd_xil_timer_corrected = xsd_xil_timer_corrected - (((uint32_T)
    (profileTimerRead(xsd_xil_timer_unfreeze))) - xsd_xil_timer_unfreeze);
}

void xilProfilingTimerUnFreezeInternal(void)
{
  xsd_xil_timer_unfreeze = ( uint32_T ) (profileTimerRead(xsd_xil_timer_unfreeze));
}

void xilProfilingTimerFreeze(void)
{
  if (xsd_xil_freezing_busy == 0) {
    xilProfilingTimerFreezeInternal();
  }                                    /* if */
}

void xilProfilingTimerUnFreeze(void)
{
  if (xsd_xil_freezing_busy == 0) {
    xilProfilingTimerUnFreezeInternal();
  }                                    /* if */
}

void taskTimeStart(uint32_T sectionId)
{
  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionId);
  xilProfilingTimerUnFreezeInternal();
}

void taskTimeEnd(uint32_T sectionId)
{
  uint32_T sectionIdNeg = ~sectionId;
  xilProfilingTimerFreezeInternal();

  /* Send execution profiling data to host */
  xilUploadProfilingData(sectionIdNeg);
}

/* Code instrumentation method(s) for model TestPilAdc */
void taskTimeStart_TestPilAdc(uint32_T sectionId)
{
  taskTimeStart(taskTimeStart_TestPilAdc_offset + sectionId);
}

void taskTimeEnd_TestPilAdc(uint32_T sectionId)
{
  taskTimeEnd(taskTimeEnd_TestPilAdc_offset + sectionId);
}
