/**
 * EUSART1 Generated Driver API Header File
 * 
 * @file junoke_eye_commande.c
 * 
 * @ingroup junoke
 * 
 * @brief This is the generated driver implementation file for the JUNOKE COMMANDE
 *
 * @version JUNOKE COMMANDE Version 1.0
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

/**
  Section: Included Files
*/
#include "junoke_eye_commande.h"

//-- Generic functions
uint8_t _send_eye_acked_cmd(char cmd[]){
    uint8_t rcv[5];
    uint8_t cmp = 0;
    uint8_t cmp2 = 0;
    uint8_t value_final=0;
    bool new_dist=false;
    char * endPtr;
    
    do{
        cmp++;
        printf("%s", cmd);
        Timer_66ms_Start();
        while(!EUSART1_IsRxReady());
        Timer_66ms_Stop();
        rcv[cmp2] = EUSART1_Read();
        if(rcv[cmp2]!=0x30){
            cmp2++;
            do{
                Timer_66ms_Start();
                while(!EUSART1_IsRxReady());
                Timer_66ms_Stop();
                rcv[cmp2] = EUSART1_Read();
                cmp2++;
            }while(rcv[cmp2-1]!=0x0A);
            new_dist = true;
        }
    }while(cmp<=5 && !new_dist);
    if(cmp>=5) asm("RESET");
    value_final = (uint8_t)strtoul((char*)rcv, &endPtr, 10);
    return value_final;
}

uint8_t _send_eye_simple_cmd(char cmd[])
{
    char cmdfull[30];
    sprintf(cmdfull, "%s,0,0,0,0\n", cmd);
    return _send_eye_acked_cmd(cmdfull);
}

//-- Predetermined Eye Functions
uint8_t ultrason_distance()
{
    return _send_eye_simple_cmd(DISTANCE_CMD);
}
