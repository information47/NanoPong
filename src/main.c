#include <avr/io.h>
#include <util/delay.h>

#include "game.h"

// Déclaration des fonctions
// void setup();
// void loop();
// void clear_led();
// void set_ball(int x, int y);
// void draw_paddle(struct paddle* p);
// void draw_ball(struct ball* b);

// Déclaration des variables globales
int paddle_left_x = 0;
int paddle_left_y = 0;
int paddle_right_x = 7;
int paddle_right_y = 0;
int ball_x = 3;
int ball_y = 0;
int ball_dx = 1;
int ball_dy = 1;

// Déclaration des structures pour les raquettes et la balle
struct paddle {
  int x;
  int y;
  int width;
  int height;
};

struct ball {
  int x;
  int y;
  int dx;
  int dy;
};

struct paddle paddle_left = {0, 0, 1, 3};
struct paddle paddle_right = {7, 0, 1, 3};
struct ball ball = {3, 0, 1, 1};

int main() {
  setup();

  // Boucle pour tester l'affichage des raquettes et de la balle
  while (1) {
    // Effacer l'écran de LED
    clear_led();

    // Dessiner les raquettes et la balle
    draw_paddle(&paddle_left);
    draw_paddle(&paddle_right);
    draw_ball(&ball);

    // Attendre un court instant avant de répéter la boucle
    _delay_ms(100);
  }

  return 0;
}
