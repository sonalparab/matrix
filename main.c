#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  //struct matrix *edges;

  /*
  edges = new_matrix(4, 4);

  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );*/

  struct matrix *test;

  test = new_matrix(4,4);
  ident(test);
  print_matrix(test);

  free_matrix(test);
  
}
