/* 
 * File: junoke_song_commande.h  
 * Author: Olivier Nasrallah
 * Revision history: 1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef JUNOKE_SONG_COMMANDE_H
#define JUNOKE_SONG_COMMANDE_H

//----------------------------------------------------------
// INCLUDE FILES
//----------------------------------------------------------
#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/system/system.h"

//----------------------------------------------------------
// TYPES DEFINITIONS
//----------------------------------------------------------
//-- Sounds
typedef enum 
{
    NOTE_C0     = 163,  //C0
    NOTE_Db0    = 173,  //C#0/Db0
    NOTE_D0     = 183,  //D0
    NOTE_Eb0    = 194,  //D#0/Eb0
    NOTE_E0     = 206,  //E0
    NOTE_F0     = 218,  //F0
    NOTE_Gb0    = 231,  //F#0/Gb0
    NOTE_G0     = 245,  //G0
    NOTE_Ab0    = 259,  //G#0/Ab0
    NOTE_A0     = 275,  //A0
    NOTE_Bb0    = 291,  //A#0/Bb0
    NOTE_B0     = 308,  //B0
    NOTE_C1     = 327,  //C1
    NOTE_Db1    = 346,  //C#1/Db1
    NOTE_D1     = 367,  //D1
    NOTE_Eb1    = 388,  //D#1/Eb1
    NOTE_E1     = 412,  //E1
    NOTE_F1     = 436,  //F1
    NOTE_Gb1    = 462,  //F#1/Gb1
    NOTE_G1     = 490,  //G1
    NOTE_Ab1    = 519,  //G#1/Ab1
    NOTE_A1     = 550,  //A1
    NOTE_Bb1    = 582,  //A#1/Bb1
    NOTE_B1     = 617,  //B1
    NOTE_C2     = 654,  //C2 (Middle C)
    NOTE_Db2    = 693,  //C#2/Db2
    NOTE_D2     = 734,  //D2
    NOTE_Eb2    = 777,  //D#2/Eb2
    NOTE_E2     = 824,  //E2
    NOTE_F2     = 873,  //F2
    NOTE_Gb2    = 925,  //F#2/Gb2
    NOTE_G2     = 980,  //G2
    NOTE_Ab2    = 1038,  //G#2/Ab2
    NOTE_A2     = 1100,  //A2
    NOTE_Bb2    = 1165,  //A#2/Bb2
    NOTE_B2     = 1234,  //B2
    NOTE_C3     = 1308,  //C3
    NOTE_Db3    = 1385,  //C#3/Db3
    NOTE_D3     = 1468,  //D3
    NOTE_Eb3    = 1555,  //D#3/Eb3
    NOTE_E3     = 1648,  //E3
    NOTE_F3     = 1746,  //F3
    NOTE_Gb3    = 1850,  //F#3/Gb3
    NOTE_G3     = 1960,  //G3
    NOTE_Ab3    = 2076,  //G#3/Ab3
    NOTE_A3     = 2200,  //A3
    NOTE_Bb3    = 2330,  //A#3/Bb3
    NOTE_B3     = 2469,  //B3
    NOTE_C4     = 2616,  //C4
    NOTE_Db4    = 2771,  //C#4/Db4
    NOTE_D4     = 2936,  //D4
    NOTE_Eb4    = 3111,  //D#4/Eb4
    NOTE_E4     = 3296,  //E4
    NOTE_F4     = 3492,  //F4
    NOTE_Gb4    = 3699,  //F#4/Gb4
    NOTE_G4     = 3920,  //G4
    NOTE_Ab4    = 4153,  //G#4/Ab4
    NOTE_A4     = 4400,  //A4
    NOTE_Bb4    = 4661,  //A#4/Bb4
    NOTE_B4     = 4938,  //B4
    NOTE_C5     = 5232,  //C5
	NOTE_Db5    = 5543,  //C#5/Db5
	NOTE_D5     = 5873,  //D5
	NOTE_Eb5    = 6222,  //D#5/Eb5
	NOTE_E5     = 6592,  //E5
	NOTE_F5     = 6984,  //F5
	NOTE_Gb5    = 7399,  //F#5/Gb5
	NOTE_G5     = 7839,  //G5
	NOTE_Ab5    = 8306,  //G#5/Ab5
	NOTE_A5     = 8800,  //A5
	NOTE_Bb5    = 9323,  //A#5/Bb5
	NOTE_B5     = 9877,  //B5
	NOTE_C6     = 10465,  //C6
	NOTE_Db6    = 11087,  //C#6/Db6
	NOTE_D6     = 11746,  //D6
	NOTE_Eb6    = 12445,  //D#6/Eb6
	NOTE_E6     = 13185,  //E6
	NOTE_F6     = 13969,  //F6
	NOTE_Gb6    = 14799,  //F#6/Gb6
	NOTE_G6     = 15679,  //G6
	NOTE_Ab6    = 16612,  //G#6/Ab6
	NOTE_A6     = 17600,  //A6
	NOTE_Bb6    = 18646,  //A#6/Bb6
	NOTE_B6     = 19755,  //B6
	NOTE_C7     = 20930,  //C7
	NOTE_Db7    = 22174,  //C#7/Db7
	NOTE_D7     = 23493,  //D7
	NOTE_Eb7    = 24890,  //D#7/Eb7
	NOTE_E7     = 26370,  //E7
	NOTE_F7     = 27938,  //F7
	NOTE_Gb7    = 29599,  //F#7/Gb7
	NOTE_G7     = 31359,  //G7
	NOTE_Ab7    = 33224,  //G#7/Ab7
	NOTE_A7     = 35200,  //A7
	NOTE_Bb7    = 37293,  //A#7/Bb7
	NOTE_B7     = 39510,  //B7
	NOTE_C8     = 41860,  //C8
	NOTE_Db8    = 44349,  //C#8/Db8
	NOTE_D8     = 46986,  //D8
	NOTE_Eb8    = 49780   //D#8/Eb8
}T_NOTE;

typedef enum 
{
    SING_CONNECTION = 0,
    SING_DISCONNECTION,
    SING_BUTTON_PUSHED,
    SING_MODE1,
    SING_MODE2,
    SING_MODE3,
    SING_SURPRISE,
    SING_OHOOH,
    SING_OHOOH2,
    SING_CUDDLY,
    SING_SLEEPING,
    SING_HAPPY,
    SING_SUPERHAPPY,
    SING_SAD,
    SING_CONFUSED,
    SING_FART1,
    SING_FART2,
    SING_FART3
} T_SONG;

//----------------------------------------------------------
// DEFINES
//----------------------------------------------------------
#define TONE_CMD "TONE"
#define SING_CMD "SING"
#define BUZZERH_CMD "BUZZERH"
#define BUZZERL_CMD "BUZZERL"

//----------------------------------------------------------
// FUNCTIONS
//----------------------------------------------------------
//-- Predetermined Song Functions
void buzzer_tone (T_NOTE noteFrequency, uint16_t noteDuration, uint8_t silentDuration);
void buzzer_sing(T_SONG songName);
void buzzer_high();
void buzzer_low();

#endif	/* JUNOKE_SONG_COMMANDE_H */

