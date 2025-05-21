 /*
 * MAIN Application File
 * @file main.c
 * @defgroup main MAIN
 * @brief Application MAIN file to test the buzzer
*/

//----------------------------------------------------------
// INCLUDE FILES
//----------------------------------------------------------
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "junoke_song_commande.h"
#include "junoke_eye_commande.h"

//----------------------------------------------------------
// MAIN APPLICATION
//----------------------------------------------------------
int main(void)
{
    uint8_t distance, abc;
    //----------------------------------------------------------
    // initialisation du microcontroleur
    SYSTEM_Initialize(); // NE PAS SUPPIRMER CETTE LIGNE DE CODE
    //----------------------------------------------------------
{
        
}
    // VOTRE CODE CI-DESSOUS
    // INSTRUCTIONS EXECUTEES UNE SEULE FOIS AU DEMARRAGE
    //----------------------------------------------------------
    
    while(1){
        //----------------------------------------------------------
        // VOTRE CODE CI-DESSOUS
        // INSTRUCTIONS EXECUTEES EN BOUCLE INDEFINIMENT
        //----------------------------------------------------------
        distance = ultrason_distance();
        DELAY_milliseconds(200);
        abc=distance;
        
         if (distance <= 10){
            buzzer_tone(1308, 50,0);
            
         } else if (distance <= 15){ 
                buzzer_sing(SING_OHOOH);
               
         } else if (distance <= 20) {
                buzzer_sing(SING_HAPPY);
             }else{
                buzzer_tone(2936, 50, 0);
        
    }
  }
}
//----------------------------------------------------------
// FIN DU CODE
//----------------------------------------------------------
