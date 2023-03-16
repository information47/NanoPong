#ifndef game_h
#define game_h

#include "nanolib.h"

void setup();
void loop();
void clear_led();
void set_point(int x, int y, int color);
void draw_paddle(struct paddle* p);
void draw_ball(struct ball* b);

#endif