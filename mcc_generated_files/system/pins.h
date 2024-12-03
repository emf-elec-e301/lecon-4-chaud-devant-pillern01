/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA4 aliases
#define UART_TX_PIN_TRIS                 TRISAbits.TRISA4
#define UART_TX_PIN_LAT                  LATAbits.LATA4
#define UART_TX_PIN_PORT                 PORTAbits.RA4
#define UART_TX_PIN_WPU                  WPUAbits.WPUA4
#define UART_TX_PIN_OD                   ODCONAbits.ODCA4
#define UART_TX_PIN_ANS                  ANSELAbits.ANSA4
#define UART_TX_PIN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define UART_TX_PIN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define UART_TX_PIN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define UART_TX_PIN_GetValue()           PORTAbits.RA4
#define UART_TX_PIN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define UART_TX_PIN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define UART_TX_PIN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define UART_TX_PIN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define UART_TX_PIN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define UART_TX_PIN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define UART_TX_PIN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define UART_TX_PIN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define UART_RX_PIN_TRIS                 TRISAbits.TRISA5
#define UART_RX_PIN_LAT                  LATAbits.LATA5
#define UART_RX_PIN_PORT                 PORTAbits.RA5
#define UART_RX_PIN_WPU                  WPUAbits.WPUA5
#define UART_RX_PIN_OD                   ODCONAbits.ODCA5
#define UART_RX_PIN_ANS                  ANSELAbits.ANSA5
#define UART_RX_PIN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define UART_RX_PIN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define UART_RX_PIN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define UART_RX_PIN_GetValue()           PORTAbits.RA5
#define UART_RX_PIN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define UART_RX_PIN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define UART_RX_PIN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define UART_RX_PIN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define UART_RX_PIN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define UART_RX_PIN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define UART_RX_PIN_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define UART_RX_PIN_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/