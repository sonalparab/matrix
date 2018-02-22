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

  //Matrix Testing
  struct matrix *m0,*m1,*m2;

  printf("Testing Identity Matrix\n");
  
  printf("m0: \n");
  m0 = new_matrix(3,3);
  ident(m0);
  print_matrix(m0);
  printf("\n");

  printf("Testing Matrix Multiplication\n");
  
  printf("m1: \n");
  m1 = new_matrix(3,3);
  add_point(m1,1,2,3);
  add_point(m1,4,5,6);
  add_point(m1,7,8,9);
  print_matrix(m1);
  printf("\n");

  printf("m0 * m1 -> m1\n");
  matrix_mult(m0,m1);
  print_matrix(m1);
  printf("\n");
  
  printf("m2: \n");
  m2 = new_matrix(3,2);
  int i,j,k;
  k = 1;
  for(i=0;i<3;i++){
    for(j=0;j<2;j++){
      m2->m[i][j] = k;
      k++;
    }
  }
  print_matrix(m2);
  printf("\n");

  printf("m2 * m1\n");
  matrix_mult(m2,m1);
  printf("\n");
  
  printf("m1 * m2 -> m2\n");
  matrix_mult(m1,m2);
  print_matrix(m2);
  printf("\n");
  
  free_matrix(m0);
  free_matrix(m1);
  free_matrix(m2);


  //image creation
  struct matrix *edges;

  clear_screen(s);
   
  edges = new_matrix(4, 4);

  int a = 10;
  int b = 490;
  
  while(a <= b){
    add_edge(edges,a,b,0,b,b,0);
    add_edge(edges,b,b,0,b,a,0);
    add_edge(edges,b,a,0,a,a,0);
    add_edge(edges,a,a,0,a,b,0);
    c.red = (a + 15) % 256;
    c.green = b % 256;
    c.blue = 250;
    a += 10;
    b -= 10;
    draw_lines(edges, s, c);
    free_matrix(edges);
    edges = new_matrix(4,4);
  }

  display(s);
  save_extension(s, "edges.png");
  free_matrix(edges);
  
}
