/**
 * EUSART1 Generated Driver API Header File
 * 
 * @file junoke_song_commande.c
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
#include "junoke_song_commande.h"

//-- Generic functions
void _send_song_acked_cmd(char cmd[]){
    uint8_t rcv, cmp;
    cmp=0;
    do{
        cmp++;
        printf("%s", cmd);
        Timer_66ms_Start();
        while(!EUSART1_IsRxReady());
        Timer_66ms_Stop();
        rcv = EUSART1_Read();
    }while(rcv!=0x31 && cmp<=5);
    if(cmp>=5) asm("RESET");
}

void _send_song_0param_cmd(char cmd[])
{
    char cmdfull[30];
    sprintf(cmdfull, "%s,0,0,0,0\n", cmd);
    _send_song_acked_cmd(cmdfull);
}

void _send_song_1param_cmd(char cmd[], T_SONG p1)
{
    char cmdfull[30];
    sprintf(cmdfull, "%s,%u,0,0,0\n", cmd, (uint8_t)p1);
    _send_song_acked_cmd(cmdfull);
}

void _send_song_3param_cmd(char cmd[], T_NOTE p1, uint16_t p2, uint8_t p3)
{
    char cmdfull[30];
    sprintf(cmdfull, "%s,%u,%u,%u,0\n", cmd, p1, p2, p3);
    _send_song_acked_cmd(cmdfull);
}

//-- Sounds
void buzzer_tone(T_NOTE noteFrequency, uint16_t noteDuration, uint8_t silentDuration)
{
    _send_song_3param_cmd(TONE_CMD, noteFrequency, noteDuration, silentDuration);
}

void buzzer_sing(T_SONG songName)
{
    _send_song_1param_cmd(SING_CMD, songName);
}

void buzzer_high(void)
{
    _send_song_0param_cmd(BUZZERH_CMD);
}

void buzzer_low(void)
{
    _send_song_0param_cmd(BUZZERL_CMD);
}
