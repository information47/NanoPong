#include <stdbool.h>
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

typedef struct s_balle{
    // Position
    int x;
    int y;
    // Directions:   droite = 1, gauche = -1, ne bouge pas = 0
    //               haut = 1, bas = -1, ne bouge pas = 0;
    int vertical_velocity;
    int horizontal_velocity;

} balle;

typedef struct s_raquet{
    // position horizontal
    int x;
    // position vertical
    int y;
    //score
    int score;

} raquette;