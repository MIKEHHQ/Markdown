/*
 * File: TestPilAdc_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "TestPilAdc_ca.h"

CA_HWImpl_TestResults CA_TestPilAdc_HWRes;
CA_PWS_TestResults CA_TestPilAdc_PWSRes;
const CA_HWImpl CA_TestPilAdc_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "STMicroelectronics->STM32 32-bit Cortex-M",/* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_TestPilAdc_ActHW;
void TestPilAdc_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_TestPilAdc_ActHW, &CA_TestPilAdc_ExpHW,
    &CA_TestPilAdc_PWSRes);
  caVerifyHWImpl(&CA_TestPilAdc_ActHW, &CA_TestPilAdc_ExpHW,
                 &CA_TestPilAdc_HWRes);
}
