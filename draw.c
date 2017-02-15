#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int B, A, dx, dy;
  if(x1 < x0){
    draw_line(x1,y1,x0,y0,s,c);
  }
  B = x0 - x1;
  A = y1 - y0;
  dx = -B;
  dy = A;
  //OCTANT I
  if(dy > 0 && dx >= dy){
    int d = B+2*A;
    int y = y0;
    int x = x0;
    while (x <= x1) {
      plot(s,c,x,y);
      if(d > 0){
	d += 2*B;
	y++;
      }
      d += 2*A;
      x++;
    }
  }
  //OCTANT II
  else if(dy > 0 && dy > dx){
    int d = B+2*A;
    int y = y0;
    int x = x0;
    while (y <= y1) {
      plot(s,c,x,y);
      if(d < 0){
	d += 2*A;
	x++;
      }
      d += 2*B;
      y++;
    }
  }
  //OCTANT VIII
  else if(dy < 0 && (-dy) >= dx){
    int d = 2*A-B;
    int y = y0;
    int x = x0;
    while (y >= y1) {
      plot(s,c,x,y);
      if(d > 0){
        d += 2*A;
        x++;
      }
      d -= 2*B;
      y--;
    }

  }
  //OCTANT VII
  else{
    int d = A-2*B;
    int y = y0;
    int x = x0;
    while (x <= x1) {
      plot(s,c,x,y);
      if(d < 0){
        d -= 2*B;
        y--;
      }
      d += 2*A;
      x++;
    }

  }
}
