#ifndef _BACKPROP_KERNEL_H_
#define _BACKPROP_KERNEL_H_

#include "backprop.h"

void bpnn_train_kernel(BPNN *net, float *eo, float *eh);

#endif

