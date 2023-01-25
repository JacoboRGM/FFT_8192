/*
 * complex_typedefs.h
 *
 *  Created on: 28 dic. 2022
 *      Author: jacobo.gonzalez
 */

#ifndef LIB_DSP_COMPLEX_TYPEDEFS_H_
#define LIB_DSP_COMPLEX_TYPEDEFS_H_

#include <stdio.h>
#include <stdlib.h>
#include "arm_math.h"
#include "arm_const_structs.h"

//typedef for complex number float 32
typedef struct{
    float32_t real;
    float32_t complex;
}complexNumber;

//functions complex

//mult of two complex
complexNumber complexMult_(complexNumber a,complexNumber b);

//sum of two complex
complexNumber complexSum_(complexNumber a,complexNumber b);

//rest of two complex
complexNumber complexRest_(complexNumber a,complexNumber b);



#endif /* LIB_DSP_COMPLEX_TYPEDEFS_H_ */
