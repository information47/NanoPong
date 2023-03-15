#include "nanolib.h"
#include <stdlib.h>
#include <util/delay.h>


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



int main(){
    init_master_SPI(SPI_MODE_0, SPI_MSB_FIRST, SPI_PRESCALER_8);
    init_block_USART0();

    init_input_GPIO(PC1, PULLUP); // up left
    init_input_GPIO(PC0, PULLUP); // down left

    init_input_GPIO(PD3, PULLUP); // up right
    init_input_GPIO(PD2, PULLUP); // down right

    for (;;) {
    t_pin_state  state = read_input_GPIO(PC1);
    if (state == LOW){
        printf("button enfoncé");
    }
   }
    







    return 0;
}