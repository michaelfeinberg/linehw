#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x1 > x0){
    int B = x0 - x1;
    int A = y1 - y0;
    int dx = -B;
  }else{
    int B = x1 - x0;
    int A = y0 - y1;
    int dx = -B;
  }
  int dy = A;
  //OCTANT I
  if(dy > 0 && dx > dy){
    int d = B+2A;
    int y = y0;
    int x = x0;
    while (x <= x1) {
      plot(s,c,x,y);
      if(d > 0){
	d += 2B;
	y++;
      }
      d += 2A;
      x++;
    }
  }
  //OCTANT II
  else if(dy > 0 && dy > dx){
    int d = B+2A;
    int y = y0;
    int x = x0;
    while (y <= y1) {
      plot(s,c,x,y);
      if(d < 0){
	d += 2A;
	x++;
      }
      d += 2B;
      y++;
    }
  }
  //OCTANT VII
  else if(dy < 0 && (-dy) > dx){
    
  }
  //OCTANT VIII
  else{

  }
}
