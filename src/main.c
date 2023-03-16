#include <avr/io.h>
#include "nanolib.h"
#include "nanoponglib.h"
#include <util/delay.h>
#include <stdlib.h>

void check_score(raquette *raquette1, raquette *raquette2)
{
    if (raquette1->score == 3)
    {
        write_output_GPIO(A5, HIGH);
    }
    else if (raquette1->score == 2)
    {
        write_output_GPIO(A4, HIGH);
    }
    else if (raquette1->score == 1)
    {
        write_output_GPIO(A3, HIGH);
    }
    if (raquette2->score == 3)
    {
        write_output_GPIO(D7, HIGH);
    }
    else if (raquette2->score == 2)
    {
        write_output_GPIO(D6, HIGH);
    }
    else if (raquette2->score == 1)
    {
        write_output_GPIO(D5, HIGH);
    }
}

void prestart() {
    uint8_t one[8] = {
        0b00000000, 
        0b00000000, 
        0b00000000, 
        0b10010010, 
        0b10010010, 
        0b11111110, 
        0b00000000, 
        0b00000000
    };

    write_MAX7219(one);
    _delay_ms(1000);

    uint8_t two[8] = {
        0b00000000, 
        0b00000000, 
        0b00000000, 
        0b11110010, 
        0b10010010, 
        0b10011110, 
        0b00000000, 
        0b00000000
    };

    write_MAX7219(two);
    _delay_ms(1000);

    uint8_t three[8] = {
        0b00000000, 
        0b00000000, 
        0b00000000, 
        0b10000100, 
        0b11111110, 
        0b10000000, 
        0b00000000, 
        0b00000000
    };

    write_MAX7219(three);
    _delay_ms(1000);
}

void start(balle *balle, raquette *raquette1, raquette *raquette2)
{
    balle->y = 1;

    check_score(raquette1, raquette2);

    init_ADC(ADC_AVCC, ADC_RIGHT_ADJUST, ADC_NO_INTERRUPT, ADC_PRESCALER_128);
    srand(analog_read(A7));

    // Spawn Horizontal
    if (rand() % 2 == 1)
    {
        balle->horizontal_velocity = 1;
        balle->x = 1;
    }
    else
    {
        balle->horizontal_velocity = -1;
        balle->x = 6;
    }

    srand(analog_read(A7));

    // Spawn Vertical
    int randVertical = rand() % 6;
    balle->y = randVertical + 1;
    raquette1->y = randVertical + 1;
    raquette2->y = randVertical + 1;

    balle->vertical_velocity = 0;

    init_MAX7219();
    clear_MAX7219();
}

void move_raq(raquette *raq, int x)
{

    t_pin_state state1 = read_input_GPIO(A1);
    t_pin_state state2 = read_input_GPIO(A0);
    t_pin_state state3 = read_input_GPIO(D2);
    t_pin_state state4 = read_input_GPIO(D3);

    raq->x = x;

    if (state1 == LOW)
    {
        raq->y += 1;
        printf("%d\n", raq->y);
    }
    else if (state2 == LOW)
    {
        raq->y -= 1;
        printf("%d\n", raq->y);
    }
    if (state3 == LOW)
    {
        raq->y += 1;
        printf("%d\n", raq->y);
    }
    else if (state4 == LOW)
    {
        raq->y -= 1;
        printf("%d\n", raq->y);
    }
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

void check_collision_mur(balle *balle)
{
    if ((balle->y == 0 && balle->vertical_velocity == -1) || (balle->y == 7 && balle->vertical_velocity == 1))
    {
        balle->vertical_velocity *= -1;
    }
}

void check_collision_raquette(balle *balle, raquette *raquette1, raquette *raquette2)
{
    if (balle->x == 1)
    {
        if (balle->y == raquette1->y + 1)
        {
            balle->horizontal_velocity *= -1;
            balle->vertical_velocity = 0;
        }
        else if (balle->y == raquette1->y || (balle->y == raquette1->y - 1 && balle->vertical_velocity == 1))
        {
            balle->vertical_velocity = -1;
            balle->horizontal_velocity *= -1;
        }
        else if (balle->y == raquette1->y + 2 || (balle->y == raquette1->y + 3 && balle->vertical_velocity == -1))
        {
            balle->vertical_velocity = 1;
            balle->horizontal_velocity *= -1;
        }
    }
    else if (balle->x == 6)
    {
        if (balle->y == raquette2->y + 1)
        {
            balle->horizontal_velocity *= -1;
            balle->vertical_velocity = 0;
        }
        else if (balle->y == raquette2->y || (balle->y == raquette2->y - 1 && balle->vertical_velocity == 1))
        {
            balle->vertical_velocity = -1;
            balle->horizontal_velocity *= -1;
        }
        else if (balle->y == raquette2->y + 2 || (balle->y == raquette2->y + 3 && balle->vertical_velocity == -1))
        {
            balle->vertical_velocity = 1;
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
    int16_t delay = 300;
    init_time();
    sei();  
    init_output_GPIO(A3);
    init_output_GPIO(A4);
    init_output_GPIO(A5);

    init_output_GPIO(D5);
    init_output_GPIO(D6);
    init_output_GPIO(D7);
    init_master_SPI(SPI_MODE_0, SPI_MSB_FIRST, SPI_PRESCALER_8);
    init_block_USART0();

    init_input_GPIO(A1, PULLUP); // up left
    init_input_GPIO(A0, PULLUP); // down left

    init_input_GPIO(D3, PULLUP); // up right
    init_input_GPIO(D2, PULLUP); // down right

    balle balle;
    balle.x = 4;
    balle.y = 4;

    raquette raquette1, raquette2;
    raquette1.x = 0;
    raquette1.y = 4;
    raquette1.score = 0;

    raquette2.x = 7;
    raquette2.y = 0;
    raquette2.score = 0;
    
    prestart();
    start(&balle, &raquette1, &raquette2);
    uint32_t referenceTime = get_time();
    uint32_t timeButton = get_time();

    while (raquette1.score < 3 && raquette2.score < 3)
    {
        uint32_t now2 = get_time();
        if ((now2 - timeButton) > 100)
        {
            //lire les boutons
            t_pin_state  stateA0 = read_input_GPIO(A0);
            if (stateA0 == LOW && raquette1.y <=4){
                raquette1.y ++;
            }
            t_pin_state  stateA1 = read_input_GPIO(A1);
            if (stateA1 == LOW && raquette1.y >= 0){
                raquette1.y --;

            }
            t_pin_state  stateD2 = read_input_GPIO(D2);
            if (stateD2 == LOW && raquette2.y <=4){
                raquette2.y ++;

            }
            t_pin_state  stateD3 = read_input_GPIO(D3);
            if (stateD3 == LOW && raquette2.y >= 0){
                raquette2.y --;

            }
            timeButton = get_time();
        }
        
        
        uint32_t now = get_time();
        if (now >= referenceTime + delay){
            deplacement(&balle);
            check_collision_raquette(&balle, &raquette1, &raquette2);
            check_collision_mur(&balle);
            affichage(balle, raquette1, raquette2);
            referenceTime = get_time();
        } 

    }


    return 0;
}
