#include <xc.h>
#include "DSP.h"

int maf(int new) {
    int i = 0;
    int sum = 0;
    int out = 0;
    int stop = MAF_SIZE-1;

    // Shift buffer contents down one
    for(i=0; i<stop; i++) {
        buffer_MAF[i] = buffer_MAF[i+1];
    }
    buffer_MAF[stop] = new;   // add new data
    for(i=0; i<=stop; i++){
        sum += buffer_MAF[i];
    }
    out = ((float) sum)/((float) MAF_SIZE);
    return ((int) out);
}

int fir(int new) {
    int i = 0;
    float sum = 0;
    int stop = FIR_SIZE-1;
    for(i=0; i<stop; i++){
        buffer_FIR[i] = buffer_FIR[i+1];
    }
    buffer_FIR[stop] = new;
    for(i=0; i<=stop; i++){
        sum += kernel_FIR[i]*buffer_FIR[i];
    }
    return((int) sum);
}

int iir(int new) {
    int out = 0;
    out = ALPHA*buffer_IIR + BETA*new;
    buffer_IIR = new;
    return ((int) out);
}