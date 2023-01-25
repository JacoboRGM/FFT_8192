/**
 * main.c
 * Frist program for configuration systems
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <file.h>
#include "inc/hw_memmap.h"
#include "inc/tm4c129encpdt.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "lib_dsp/signals.h"
#include "driverlib/fpu.h"
#include "utils/uartstdio.h"
#include "mydevices/mydevices.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "lib_dsp/fft_dif.h"
#include "lib_dsp/complex_typedefs.h"
#include <math.h>
#include "driverlib/systick.h"


#define conv_length     KHZ1_15_SIG_LEN+IMP_RSP_LENGTH-1
#define OFFSET1         5
#define OFFSET2         10
void configPeripherals(void);
void pseudo_dly(int dly);

//variables de entrada
uint32_t status;
extern complexNumber signal_gen_8192[SIGNAL_COMPLEX_8192];
FFT_instance    FFT_1;

uint16_t k=0;
uint32_t loop;

uint32_t value_i, value_e;

void serial_plot_magFFT(void);


int main(void){

   configPeripherals();
   FPUEnable();
   Init_Device();

   status=FFT_DIF_INIT(&FFT_1, 8192);

   //value_i=SysTickValueGet();
   GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
   FFT_DIF(&FFT_1,(complexNumber *)signal_gen_8192);
   GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
   value_e=SysTickValueGet();
   serial_plot_magFFT();
   //printf("Time FFT=%d\r\n",(value_i-value_e));
   uint16_t index;
    while(1){

        //
        // Delay for a bit.
        //
        for(loop = 0; loop < 200000; loop++)
        {
        }
        // Turn off the LED.
        // Delay for a bit.
        //
        for(loop = 0; loop < 200000; loop++)
        {
        }
    }
}


void serial_plot_magFFT(void){

    int i=0;
    float32_t real, complex;
    printf("Number;Value\n");
    for(i=0; i< FFT_1.fft_point_number/2; i++){

        real=signal_gen_8192[i].real*signal_gen_8192[i].real;
        complex=signal_gen_8192[i].complex*signal_gen_8192[i].complex;

        printf("%d;%f\n",i,2*sqrt(real+complex)/FFT_1.fft_point_number);
        pseudo_dly(9000);
    }
}

void pseudo_dly(int dly)
{
    int i=0;
    for( i = 0; i < dly; i++ ){}
}

//configuration function
void configPeripherals(void){
    //set clock 120 MHz using PLL and OSC XTAL 25MHz
    SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ|SYSCTL_USE_PLL|SYSCTL_CFG_VCO_480, 120000000);
        //Habilita periferico GPIOB
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)){

        }
        //Habilita periferico GPIO N
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)){

        }
        //Habilita periferico GPIO J
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)){

        }
        //Como salidas
        GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0|GPIO_PIN_1);
        //Como entradas
        GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_1);
        //WPD resistor
        GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

        //selected pins for UART1

        GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        //
        // Enable UART1 functionality on GPIO Port B pins 0 and 1.
        //
        GPIOPinConfigure(GPIO_PB0_U1RX);
        GPIOPinConfigure(GPIO_PB1_U1TX);

        //Enable UART1
        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART1)){

        }
        UARTConfigSetExpClk(UART1_BASE, 120000000,115200,
                            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                            UART_CONFIG_PAR_NONE));

        UARTEnable(UART1_BASE);
        //UARTprintf config
        UARTStdioConfig(1, 115200,120000000);

        //systick
        SysTickPeriodSet(10000);
        SysTickEnable();

}
