#include <avr/io.h>
#include "nanolib.h"
#include "nanoponglib.h"
#include <util/delay.h>
#include <stdlib.h>

void check_score(raquette *raquette1, raquette *raquette2){
    if(raquette1->score == 3){
        write_output_GPIO(A5, HIGH);
    }
    else if(raquette1->score == 2){
        write_output_GPIO(A4, HIGH);
    }
    else if(raquette1->score == 1){
        write_output_GPIO(A3, HIGH);
    }
    else if(raquette2->score >= 3){
        write_output_GPIO(D7, HIGH);
    }
    else if(raquette2->score == 2){
        write_output_GPIO(D6, HIGH);
    }
    else if(raquette2->score == 1){
        write_output_GPIO(D5, HIGH);
    }
}

void start(balle *balle, raquette *raquette1, raquette *raquette2)
{
    balle->x = 4;
    balle->y = 1;

    check_score(raquette1, raquette2);

    init_ADC(ADC_AVCC, ADC_RIGHT_ADJUST, ADC_NO_INTERRUPT, ADC_PRESCALER_128);
    srand(analog_read(A7));

    if (rand() % 2 == 1)
    {
        balle->horizontal_velocity = 1;
    }
    else
    {
        balle->horizontal_velocity = -1;
    }

    balle->vertical_velocity = 0;

    init_MAX7219();
    clear_MAX7219();
}

void deplacement(balle *balle)
{
    balle->x += balle->horizontal_velocity;
    balle->y += balle->vertical_velocity;
}

void affichage(balle balle, raquette raquette1, raquette raquette2)
{
    uint8_t display[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    // Display balle
    display[balle.x] = (1 << balle.y);
    // Display raquette 1
    display[raquette1.x] = (7 << raquette1.y);
    // Display raquette 2
    display[raquette2.x] = (7 << raquette2.y);
    write_MAX7219(display);
}

void check_collision_raquette(balle *balle, raquette *raquette1, raquette *raquette2)
{
    if (balle->x == 1)
    {
        if (balle->y == raquette1->y || balle->y == raquette1->y + 1 || balle->y == raquette1->y + 2)
        {
            balle->horizontal_velocity *= -1;
        }
    }
    else if (balle->x == 6)
    {
        if (balle->y == raquette2->y || balle->y == raquette2->y + 1 || balle->y == raquette2->y + 2)
        {
            balle->horizontal_velocity *= -1;
        }
    }
    else if (balle->x == 0)
    {
        // MORT
        raquette2->score++;
        start(balle, raquette1, raquette2);
        _delay_ms(2000);
    }
    else if (balle->x == 7)
    {
        // MORT
        raquette1->score++;
        start(balle, raquette1, raquette2);
        _delay_ms(2000);
    }
}

int main()
{
    init_output_GPIO(A3);
    init_output_GPIO(A4);
    init_output_GPIO(A5);

    init_output_GPIO(D5);
    init_output_GPIO(D6);
    init_output_GPIO(D7);

    balle balle;
    balle.x = 4;
    balle.y = 4;

    raquette raquette1, raquette2;
    raquette1.x = 0;
    raquette1.y = 4;
    raquette1.score = 0;

    raquette2.x = 7;
    raquette2.y = 0;
    raquette1.score = 0;

    start(&balle, &raquette1, &raquette2);

    // Boucle infinie
    while (raquette1.score < 3 && raquette2.score < 3)
    {
        deplacement(&balle);
        check_collision_raquette(&balle, &raquette1, &raquette2);
        affichage(balle, raquette1, raquette2);
        _delay_ms(200);
    }

    return 0;
}
