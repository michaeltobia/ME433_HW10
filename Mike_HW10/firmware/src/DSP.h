#ifndef DSP_H__
#define DSP_H__

#define MAF_SIZE 4
#define FIR_SIZE 7
#define ALPHA 0.9
#define BETA 0.1

int buffer_MAF[MAF_SIZE] = {0};
int buffer_FIR[FIR_SIZE] = {0};
float kernel_FIR[FIR_SIZE] = {0.0212, 0.0897, 0.2343, 0.3094, 0.2343, 0.0897, 0.0212};
int buffer_IIR = 0;

int maf(int);
int fir(int);
int iir(int);


#endif