#include "nanolib.h"
#include <stdlib.h>
#include <util/delay.h>
#include "nanoponglib.h"


// typedef struct s_balle
// {
//     //Position
//     int verticale;
//     uint8_t horizontal;

//     //Directions:   droite = 1, gauche = -1, ne bouge pas = 0
//     //              haut = 1, bas = -1, ne bouge pas = 0;
//     int vertical_move;
//     int horizontal_move;
// } balle;

// typedef struct s_raquet
// {
    
// } raquette;


// //deplacement du joueur gauche------------------------------------------------------------------------------------

// uint8_t deplacementJoueurG(posG)
// {
//     if (posG < 170)
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b11100000);
//         return 0b11100000;
//     }
//     else if(posG < 340)
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b01110000);
//         return 0b01110000;
//     }
//     else if(posG < 510)
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b00111000);
//         return 0b00111000;
//     }
//     else if(posG < 680)
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b00011100);
//         return 0b00011100;
//     }
//     else if(posG < 850)
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b00001110);
//         return 0b00001110;
//     }
//     else
//     {
//         write_column_MAX7219(MAX7219_COLUMN0, 0b00000111);
//         return 0b00000111;
//     }
// }


// //deplacement du joueur droit-------------------------------------------------------------------------------------

// uint8_t deplacementJoueurD(int posD)
// {
//     if (posD < 170)
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b11100000);
//         return 0b11100000;
//     }
//     else if(posD < 340)
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b01110000);
//         return 0b01110000;
//     }
//     else if(posD < 510)
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b00111000);
//         return 0b00111000;
//     }
//     else if(posD < 680)
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b00011100);
//         return 0b00011100;
//     }
//     else if(posD < 850)
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b00001110);
//         return 0b00001110;
//     }
//     else
//     {
//         write_column_MAX7219(MAX7219_COLUMN7, 0b00000111);
//         return 0b00000111;
//     }
// }

int readButtons(int buttonState[]){
    t_pin_state  stateA0 = read_input_GPIO(A0);
    t_pin_state  stateA1 = read_input_GPIO(A1);
    t_pin_state  stateD2 = read_input_GPIO(D2);
    t_pin_state  stateD3 = read_input_GPIO(D3);
    
    buttonState[0] = stateA0;
    buttonState[1] = stateA1;
    buttonState[2] = stateD2;
    buttonState[3] = stateD3;

    return buttonState;    
}

int main(){
    init_master_SPI(SPI_MODE_0, SPI_MSB_FIRST, SPI_PRESCALER_8);
    init_block_USART0();

    init_input_GPIO(A1, PULLUP); // up left
    init_input_GPIO(A0, PULLUP); // down left

    init_input_GPIO(D3, PULLUP); // up right
    init_input_GPIO(D2, PULLUP); // down right
    // t_nano_pin buttonPins[] = {A0, A1, D2, D3};

    for (;;) {
    
    t_pin_state  stateA0 = read_input_GPIO(A0);
    if (stateA0 == LOW){
        printf("bouton A0 enfoncé");
    }
    t_pin_state  stateA1 = read_input_GPIO(A1);
    if (stateA1 == LOW){
        printf("bouton A1 enfoncé");
    }
    t_pin_state  stateD2 = read_input_GPIO(D2);
    if (stateD2 == LOW){
        printf("bouton D2 enfoncé");
    }
    t_pin_state  stateD3 = read_input_GPIO(D3);
    if (stateD3 == LOW){
        printf("bouton D3 enfoncé");
    }


    if (stateA0 == LOW) {

    }
   }
   
    return 0;
   
   }