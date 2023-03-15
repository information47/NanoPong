#include "nanolib.h"
#include <stdlib.h>
#include <util/delay.h>
#include "nanoponglib.h"


void move_raq(raquette* raq, int x){

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
    
    raquette raq;

    for(;;){
        move_raq(&raq,0);
        move_raq(&raq,7);
        
    }




    return 0;
}