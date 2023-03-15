#include "nanolib.h"
#include <stdlib.h>
#include <util/delay.h>
#include "nanoponglib.h"

//deplacement du joueur gauche------------------------------------------------------------------------------------

uint8_t deplacementJoueurG(posG)
{
    if (posG < 170)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b11100000);
        return 0b11100000;
    }
    else if(posG < 340)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b01110000);
        return 0b01110000;
    }
    else if(posG < 510)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00111000);
        return 0b00111000;
    }
    else if(posG < 680)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00011100);
        return 0b00011100;
    }
    else if(posG < 850)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00001110);
        return 0b00001110;
    }
    else
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00000111);
        return 0b00000111;
    }
}


//deplacement du joueur droit-------------------------------------------------------------------------------------

uint8_t deplacementJoueurD(int posD)
{
    if (posD < 170)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b11100000);
        return 0b11100000;
    }
    else if(posD < 340)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b01110000);
        return 0b01110000;
    }
    else if(posD < 510)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00111000);
        return 0b00111000;
    }
    else if(posD < 680)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00011100);
        return 0b00011100;
    }
    else if(posD < 850)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00001110);
        return 0b00001110;
    }
    else
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00000111);
        return 0b00000111;
    }
}



int main(){






    return 0;
}