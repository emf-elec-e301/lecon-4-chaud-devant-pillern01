/**
 * TMR0 Generated Driver File
 * 
 * @file tmr0.c
 * 
 * @ingroup tmr0
 * 
 * @brief  Driver implementation for the TMR0 driver
 *
 * @version TMR0 Driver Version 2.1.0
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "../tmr0.h"


const struct TMR_INTERFACE Timer_66ms = {
    .Initialize = Timer_66ms_Initialize,
    .Start = Timer_66ms_Start,
    .Stop = Timer_66ms_Stop,
    .PeriodCountSet = Timer_66ms_Reload,
    .TimeoutCallbackRegister = Timer_66ms_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*Timer_66ms_OverflowCallback)(void);
static void Timer_66ms_DefaultOverflowCallback(void);

void Timer_66ms_Initialize(void)
{
    //TMR0H 254; 
    TMR0H = 0xFE;

    //TMR0L 0; 
    TMR0L = 0x0;

    //T0CS LFINTOSC; T0CKPS 1:128; T0ASYNC synchronised; 
    T0CON1 = 0x87;


    //Set default callback for TMR0 overflow interrupt
    Timer_66ms_OverflowCallbackRegister(Timer_66ms_DefaultOverflowCallback);

    //Clear Interrupt flag before enabling the interrupt
    PIR0bits.TMR0IF = 0;
	
    //Enable TMR0 interrupt.
    PIE0bits.TMR0IE = 1;
	
    //T0OUTPS 1:1; T0EN enabled; T016BIT 8-bit; 
    T0CON0 = 0x80;
}

void Timer_66ms_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void Timer_66ms_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint8_t Timer_66ms_Read(void)
{
    uint8_t readVal;

    //Read TMR0 register, low byte only
    readVal = TMR0L;

    return readVal;
}

void Timer_66ms_Write(uint8_t timerVal)
{
    //Write to TMR0 register, low byte only
    TMR0L = timerVal;
 }

void Timer_66ms_Reload(size_t periodVal)
{
   //Write to TMR0 register, high byte only
   TMR0H = (uint8_t)periodVal;
}

void Timer_66ms_OverflowISR(void)
{
    static volatile uint16_t CountCallBack = 0;

    //Clear the TMR0 interrupt flag
    PIR0bits.TMR0IF = 0;
    //Callback function - called every 475th pass
    if (++CountCallBack >= Timer_66ms_INTERRUPT_TICKER_FACTOR)
    {
        //Ticker function call
    if(Timer_66ms_OverflowCallback)
    {
        Timer_66ms_OverflowCallback();
    }

        //Reset ticker counter
        CountCallBack = 0;
}
}

void Timer_66ms_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer_66ms_OverflowCallback = CallbackHandler;
}

static void Timer_66ms_DefaultOverflowCallback(void)
{
    asm("RESET");
}

