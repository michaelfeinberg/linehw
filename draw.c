#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int B = x0 - x1;
  int A = y1 - y0;
  int d = B/2 + A;
  int y = y0;
  int x = x0;
  while (x <= x1) {
    plot(s,c,x,y);
    if(d > 0){
      d += B;
      y++;
    }
    d += A;
    x++;
  }
}
