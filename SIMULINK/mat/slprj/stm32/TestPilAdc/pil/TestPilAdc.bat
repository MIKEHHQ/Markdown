
set MATLAB=D:\MATLAB\R2022a

"%MATLAB%\bin\%MATLAB_WIN_VER%\gmake" -f TestPilAdc.mk  GENERATE_ASAP2=0 OPTS="-DTID01EQ=0 -DPROFILING_DEFINE_UINT64_TIMER_TYPE -DCODER_ASSUMPTIONS_ENABLED=1 -DRTIOSTREAM_RX_BUFFER_BYTE_SIZE=128 -DRTIOSTREAM_TX_BUFFER_BYTE_SIZE=128 -DCODE_INSTRUMENTATION_ENABLED=1 -DMEM_UNIT_BYTES=1 -DMemUnit_T=uint8_T"
