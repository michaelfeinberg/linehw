
#include <stdio.h>

#include <string.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
  int x0,y0,x1,y1;
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);
  int i = 0;
  int j = 0;
  while(i < 5){
    while(j < 5){
      x0 = i*100;
      y0 = j*100;
      c.red = x0%256;
      c.green = y0%256;
      c.blue = (y0 - x0)%256;
      
      x1 = 0;
      y1 = 250;
      while(y1 < 500){
	draw_line(x0,y0,x1,y1,s,c);
	x1+=5;
	y1+=5;
      }
      x1 = 0;
      y1 = 250;
      while(y1 > 0){
        draw_line(x0,y0,x1,y1,s,c);
	x1+=5;
	y1-=5;
      }
      x1 = 500;
      y1 = 250;
      while(y1 < 500){
        draw_line(x0,y0,x1,y1,s,c);
        x1-=5;
        y1+=5;
      }
      x1 = 500;
      y1 = 250;
      while(y1 > 0){
        draw_line(x0,y0,x1,y1,s,c);
        x1-=5;
        y1-=5;
      }
      j++;
    }
    i++;
  }
  display(s);
  save_extension(s, "lines.png");
}  
