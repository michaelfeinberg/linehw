#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);
  int x0 = 100;
  int y0 = 100;
  int x1 = 200;
  int y1 = 200;
  draw_line(x0,y0,x1,y1,s,c);
  
  display(s);
  save_extension(s, "lines.png");
}  
