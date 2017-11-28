/***********************************
* EECS2031 - Assignment 1		   
* Filename: polyMain.c	  	
* Author: U. T. Nguyen
************************************/


#include "poly.h"

int main()
{
  int coeff1[ASIZE], exp1[ASIZE], coeff2[ASIZE], exp2[ASIZE];
  char strg[ASIZE*5];
  double x, y;

  do
  {
  init_polynom( coeff1, exp1 );
  get_polynom( coeff1, exp1 );
  polynom_to_string( coeff1, exp1, strg );
  printf( "%s\n", strg);

  init_polynom( coeff2, exp2 );
  get_polynom( coeff2, exp2 );
  polynom_to_string( coeff2, exp2, strg );
  printf( "%s\n", strg);

  add_polynom( coeff1, exp1, coeff2, exp2 );
  polynom_to_string( coeff1, exp1, strg );
  printf( "%s\n\n", strg);
  }
  while ( coeff1[0] );

  polynom_to_string( coeff2, exp2, strg );
  printf( "%s\n", strg);
  do {
    scanf( "%lf", &x );  	/* to input a double use "%lf", not "%f" */
    eval_polynom( coeff2, exp2, x, &y ); 
    printf( "p(%.4lf) = %.4lf \n", x, y ); 
  }
  while ( x );

  return 0;  /* normal termination */
}

