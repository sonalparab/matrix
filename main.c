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

  struct matrix *test,*m1,*m2,*m3;

  test = new_matrix(4,4);
  ident(test);
  print_matrix(test);
  printf("\n");

  printf("m1: \n");
  m1 = new_matrix(3,3);
  int i,j,k;
  k = 1;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      m1->m[i][j] = k;
      k++;
    }
  }
  print_matrix(m1);
  printf("\n");

  printf("m2: \n");
  m2 = new_matrix(3,2);
  k = 1;
  for(i=0;i<3;i++){
    for(j=0;j<2;j++){
      m2->m[i][j] = k;
      k++;
    }
  }
  print_matrix(m2);
  printf("\n");

  printf("m1 * m2\n");
  matrix_mult(m1,m2);
  print_matrix(m2);
  printf("\n");

  printf("reseting m2...\n");
  k = 1;
  for(i=0;i<3;i++){
    for(j=0;j<2;j++){
      m2->m[i][j] = k;
      k++;
    }
  }
  print_matrix(m2);
  printf("\n");

  printf("m3: \n");
  m3 = new_matrix(2,4);
  k = 1;
  for(i=0;i<2;i++){
    for(j=0;j<4;j++){
      m3->m[i][j] = k;
      k++;
    }
  }
  print_matrix(m3);
  printf("\n");

  printf("m2 * m3\n");
  matrix_mult(m2,m3);
  print_matrix(m3);
  printf("\n");
  
  free_matrix(test);
  free_matrix(m1);
  free_matrix(m2);
  free_matrix(m3);
  
}
