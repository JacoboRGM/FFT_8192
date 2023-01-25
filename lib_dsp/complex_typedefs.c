/*
 * complex_typedefs.c
 *
 *  Created on: 28 dic. 2022
 *      Author: jacobo.gonzalez
 */

#include <stdio.h>
#include "complex_typedefs.h"


/*complex mult*/
complexNumber complexMult_(complexNumber a, complexNumber b){
    complexNumber z;
    z.complex=0;
    z.real=0;

    z.real=(a.real*b.real) - (a.complex*b.complex);
    z.complex=(a.real*b.complex) + (b.real*a.complex);

    return z;
}


/*complex sum*/
complexNumber complexSum_(complexNumber a,complexNumber b){
    complexNumber z;
    z.complex=0;
    z.real=0;

    z.real=a.real+b.real;
    z.complex=a.complex+b.complex;

    return z;
}


/*complex rest*/
complexNumber complexRest_(complexNumber a,complexNumber b){
    complexNumber z;
    z.complex=0;
    z.real=0;

    z.real=a.real - b.real;
    z.complex=a.complex - b.complex;

    return z;
}

