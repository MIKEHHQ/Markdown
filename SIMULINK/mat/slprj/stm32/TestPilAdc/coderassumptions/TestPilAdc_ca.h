/*
 * File: TestPilAdc_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef TESTPILADC_CA_H
#define TESTPILADC_CA_H

/* preprocessor validation checks */
#include "TestPilAdc_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_TestPilAdc_HWRes;
extern CA_PWS_TestResults CA_TestPilAdc_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_TestPilAdc_ExpHW;
extern CA_HWImpl CA_TestPilAdc_ActHW;

/* entry point function to run tests */
void TestPilAdc_caRunTests(void);

#endif                                 /* TESTPILADC_CA_H */
