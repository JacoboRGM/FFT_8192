/*
 * fft_dif.h
 *
 *  Created on: 29 dic. 2022
 *      Author: jacobo.gonzalez
 */

#ifndef LIB_DSP_FFT_DIF_H_
#define LIB_DSP_FFT_DIF_H_

#include <stdio.h>
#include "complex_typedefs.h"
#include "arm_math.h"
#include "arm_const_structs.h"

#define FFT_SIZE    8192

//operating for FFT
typedef struct{
    uint16_t size_operation;
    uint16_t half_size_operation;
    uint16_t num_operation;
    uint16_t index_A;
    uint16_t index_B;
    uint16_t index_twiddle;
    uint16_t index_size;
    uint16_t index_operation;
}FFT_variables;

typedef struct{
    uint16_t        fft_point_number;       //size of FFT
    uint16_t        *bitReversal_ptr;       //bit reversal pointer
    complexNumber   *twiddleFactor_ptr;     //Twiddle Factors Pointer
    FFT_variables   variablesFFT;          //FFT variables for internal computation
}FFT_instance;

//Twiddle factors


//INIT instance FFT_DIF
uint32_t FFT_DIF_INIT(FFT_instance * FFT, uint16_t size_FFT );

//FFT RADIX 2

uint32_t FFT_DIF(FFT_instance * FFT, complexNumber * signal_input);


#endif /* LIB_DSP_FFT_DIF_H_ */
