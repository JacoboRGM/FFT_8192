/*

 * fft_dif.c
 *
 *  Created on: 29 dic. 2022
 *      Author: jacobo.gonzalez
 */
#include <stdlib.h>
#include "fft_dif.h"
#include "complex_typedefs.h"
#include "arm_math.h"
#include "twiddleFactor.h"
#include "bit_reversal.h"


/*Twiddle factors
 *
 *
 *
 * */

/*
//8 points
extern complexNumber twiddleFactor_8[TWIDDLE_FACTOR_8];
//512 points
extern complexNumber twiddleFactor_512[TWIDDLE_FACTOR_512];

//1024 points
extern complexNumber twiddleFactor_1024[TWIDDLE_FACTOR_1024];

//2048 points
extern complexNumber twiddleFactor_2048[TWIDDLE_FACTOR_2048];

//4096 points
extern complexNumber twiddleFactor_4096[TWIDDLE_FACTOR_4096];


*/
//8192 points
extern complexNumber twiddleFactor_8192[TWIDDLE_FACTOR_8192];


/*bit reversal index

 *
 *
 */

/*
extern uint16_t bit_reversal_8[BIT_REVERSAL_8];

//bit reversal 512
extern uint16_t bit_reversal_512[BIT_REVERSAL_512];

//bit reversal 1024
extern uint16_t bit_reversal_1024[BIT_REVERSAL_1024];

//bit reversal 2048
extern uint16_t bit_reversal_2048[BIT_REVERSAL_2048];

//bit reversal 4096
extern uint16_t bit_reversal_4096[BIT_REVERSAL_4096];

*/
//bit reversal 8192
extern uint16_t bit_reversal_8192[BIT_REVERSAL_8192];


//FFT DIF
uint32_t FFT_DIF_INIT(FFT_instance * FFT, uint16_t size_FFT ){

   //init the FFT object
   uint32_t error=0;

   FFT->fft_point_number=size_FFT;
/*
   switch(FFT->fft_point_number){

       case 8:
                   FFT->twiddleFactor_ptr = twiddleFactor_8;
                   FFT->bitReversal_ptr   = bit_reversal_8;
           break;

       case  512:
                   //memcpy(FFT->twiddleFactor_ptr,(complexNumber * )twiddleFactor_512,sizeof(complexNumber)*size_FFT);
                   FFT->twiddleFactor_ptr = twiddleFactor_512;
                   FFT->bitReversal_ptr   = bit_reversal_512;
                   //memcpy(FFT->bitReversal_ptr,(uint16_t* )bit_reversal_512, sizeof(uint16_t)*size_FFT);
           break;

       case 1024:
                   FFT->twiddleFactor_ptr = twiddleFactor_1024;
                   FFT->bitReversal_ptr   = bit_reversal_1024;
           break;

       case 2048:
                   FFT->twiddleFactor_ptr = twiddleFactor_2048;
                   FFT->bitReversal_ptr   = bit_reversal_2048;
           break;

       case 4096:
                   FFT->twiddleFactor_ptr = twiddleFactor_4096;
                   FFT->bitReversal_ptr   = bit_reversal_4096;
           break;

       case 8192:
                   FFT->twiddleFactor_ptr = twiddleFactor_8192;
                   FFT->bitReversal_ptr   = bit_reversal_8192;
           break;

       default:
                   error=0x01;//error in points number
           break;
   }
*/
   //dynamically allocated memory for input signal_complex
   //FFT->signal_fft = (complexNumber*) calloc(size_FFT, sizeof(32*2));
   FFT->twiddleFactor_ptr = twiddleFactor_8192;
   FFT->bitReversal_ptr   = bit_reversal_8192;
   //not error in INIT function
   return error;
}

uint32_t FFT_DIF(FFT_instance * FFT, complexNumber * signal_input){

    //put the input signal in the complex signal buffer for computation
    uint16_t i=0, k=0, number_rev=0;
    complexNumber W, temp, temp_r, bit_rev_aux_1, bit_rev_aux_2;
    uint16_t size_operation, half_size_operation, num_operation, index_A, index_B, index_twiddle;
    //perform FFT
    size_operation=FFT->fft_point_number;
    num_operation=1;
    while(size_operation > 1){
        half_size_operation   =   size_operation/2;
        for(k=0; k < num_operation; k++){
            index_A = k*size_operation;
            index_B = index_A + (half_size_operation -1);
            index_twiddle = 0;
            for(i=index_A; i <= index_B; i++){
                W=FFT->twiddleFactor_ptr[index_twiddle];
                temp=signal_input[i];
                signal_input[i]=complexSum_(temp,signal_input[i+half_size_operation]);
                temp_r=complexRest_(temp, signal_input[i+half_size_operation]);
                signal_input[i+half_size_operation]=complexMult_(W,temp_r);
                index_twiddle=index_twiddle+num_operation;
            }
        }
        num_operation=2*num_operation;
        size_operation = half_size_operation;
    }
    //re-order  output signal in bit reversal
    for(i=0; i < FFT->fft_point_number ; i++){
        number_rev = FFT->bitReversal_ptr[i];
        if(number_rev != i){
            if(number_rev > i){
                bit_rev_aux_1 = signal_input[i];
                bit_rev_aux_2 = signal_input[number_rev];
                signal_input[i] = bit_rev_aux_2;
                signal_input[number_rev] = bit_rev_aux_1;
            }
        }
    }

    return 0;
}




