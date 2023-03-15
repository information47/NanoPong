#include "nanolib.h"
#include <stdlib.h>
#include <util/delay.h>
#include "nanoponglib.h"

//deplacement du joueur gauche------------------------------------------------------------------------------------

/*uint8_t deplacementJoueurG(posG)
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
}*/

void move_raq(t_raquette* raq, int x){


    t_pin_state state1 = read_input_GPIO(A1);
    t_pin_state state2 = read_input_GPIO(A0);
    t_pin_state state3 = read_input_GPIO(D2);
    t_pin_state state4 = read_input_GPIO(D3);

    raq -> x = x;

    if(state1 == LOW){
        raq -> y +=1 ;
        printf("%d\n", raq -> y);
    }else if(state2 == LOW){
        raq -> y -=1 ;
        printf("%d\n", raq -> y);
            
    }if(state3 == LOW){
        raq -> y +=1 ;
        printf("%d\n", raq -> y);
    }else if(state4 == LOW){
        raq -> y -=1 ;
        printf("%d\n", raq -> y);
            
    }
    }

int main(){

    init_block_USART0();
    init_input_GPIO(A1,PULLUP);
    init_input_GPIO(A0,PULLUP);
    init_input_GPIO(D2,PULLUP);
    init_input_GPIO(D3,PULLUP);
    
    t_raquette raq;

    for(;;){
        move_raq(&raq,0);
        move_raq(&raq,7);
        
    }




    return 0;
}