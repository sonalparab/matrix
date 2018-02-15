#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  //switch coordinates if x1 < x0
  if(x1 < x0)
    draw_line(x1,y1,x0,y0,s,c);
  
  int x = x0;
  int y = y0;
  int d;
  int A = y1 - y0;
  int B = (x1 - x0) * -1;
  float m = (float)A / (float)(B * -1);
  
  //Octant 1
  if(0 <= m && m <= 1){
    d = (2 * A) + B;
    while (x <= x1){
      plot(s,c,x,y);
      if(d > 0){
	y++;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }

  //Octant 2
  else if(m > 1){
    d = A + (2 * B);
    while (y <= y1){
      plot(s,c,x,y);
      if(d < 0){
	x++;
	d += 2 * A;
      }
      y++;
      d += 2 * B;
    }
  }

  //Octant 8
  else if(-1 <= m && m < 0){
    d = (2 * A) - B;
    while (x <= x1){
      plot(s,c,x,y);
      if(d < 0){
	y--;
	d -= 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }

  //Octant 7
  else if(m < -1){
    d = A - (2 * B);
    while (y >= y1){
      plot(s,c,x,y);
      if(d > 0){
	x++;
	d += 2 * A;
      }
      y--;
      d -= 2 * B;
    }
  }
  
}

