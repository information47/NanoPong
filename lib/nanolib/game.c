#include <avr/io.h>

#include "game.h"

#define MSBFIRST 1

// Paramètres de la matrice de LED
#define LED_ROWS 8
#define LED_COLS 32

// Broches pour le contrôle de la matrice de LED
#define DATA_PIN 11
#define CLOCK_PIN 13
#define LATCH_PIN 10

// Définition des objets du jeu
struct paddle {
  int x;
  int y;
  int width;
  int height;
};

struct ball {
  int x;
  int y;
  int size;
};

// Initialisation des raquettes et de la balle
struct paddle paddle_left = {0, LED_ROWS/2 - 1, 3, LED_ROWS/4};
struct paddle paddle_right = {LED_COLS - 3, LED_ROWS/2 - 1, 3, LED_ROWS/4};
struct ball ball = {LED_COLS/2, LED_ROWS/2, 1};

void setup() {
  // Initialisation des broches de la matrice de LED
  DDRB |= _BV(DDB5) | _BV(DDB3) | _BV(DDB2);

  // Effacer l'écran de LED
  clear_led();

  // Afficher les raquettes et la balle
  draw_paddle(&paddle_left);
  draw_paddle(&paddle_right);
  draw_ball(&ball);
}

void loop() {
  // Ne rien faire dans la boucle principale pour l'instant
}

// Fonction pour définir la balle sur l'écran de LED
void set_ball(int x, int y) {
  PORTB &= ~_BV(PORTB2);
  for (int i = 0; i < LED_COLS; i++) {
    if (i == x) {
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST);
    } else {
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST);
    }
  }
  for (int j = 0; j < y; j++) {
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST);
  }
  PORTB |= _BV(PORTB2);
}

// Fonction pour dessiner une raquette sur l'écran de LED
void draw_paddle(struct paddle* p) {
  int i, j;

  for (i = 0; i < p->height; i++) {
    for (j = 0; j < p->width; j++) {
      set_ball(p->x + j, p->y + i);
    }
  }
}

// Fonction pour dessiner une balle sur l'écran de LED
void draw_ball(struct ball* b) {
  set_ball(b->x, b->y);
}