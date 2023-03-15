#include <stdbool.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

typedef struct s_balle
{
    //Position
    int verticale;
    uint8_t horizontal;

    //Directions:   droite = 1, gauche = -1, ne bouge pas = 0
    //              haut = 1, bas = -1, ne bouge pas = 0;
    int vertical_move;
    int horizontal_move;
} balle;


typedef struct s_raquet
{
    //position horizontal
    int x;
    //position vertical
    int y;
    

} raquette;