#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
}


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

