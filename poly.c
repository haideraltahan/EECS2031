/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c 
* Author: Al-Tahan, Haider
* Email: haideraltahan@gmail.com
* Login ID: mrfirete
************************************/

#include "poly.h"


/* 
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{
	int i;
	for(i = 0;i < ASIZE;i++){
		coeff[i] = 0;
		exp[i] = 0;
	}

}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{
	int poly_size,
		i,
		temp_coeff,
		temp_exp;
	scanf("%d", &poly_size);
	for(i = 0;i < poly_size; i++){
		scanf("%d", &temp_coeff);
		scanf("%d", &temp_exp);
		coeff[i] = temp_coeff;
		exp[i] = temp_exp;
	}
}  /* end get_polynom */

char *intToStringh(char *dest, int i) {
  if (i <= -10) {
    dest = intToStringh(dest, i/10);
  }
  *dest++ = '0' - i%10;
  return dest;
}

char *intToString(char *dest, int i) {
  char *s = dest;
  if (i < 0) {
    *s++ = '-';
  } else {
    i = -i;
  }
  *intToStringh(s, i) = '\0';
  return dest;
}

void StrgM(char s1[], char s2[]){
	int i,flag;
	for(i = 0; i < ASIZE;i++){
			if(s1[i] == '\0'){
				flag = i;
				break;
			}
	}
	for(i = 0; i < ASIZE;i++,flag++){
		if(s2[i] == '\0'){
			s1[flag] = '\0';
			break;
		}
		s1[flag] = s2[i];
	}
}
/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{
   int i, length = 0;
   s[0] = 0;
    if(coeff[i] == 0 && i == 0){
		StrgM(s, "0");
	}
   for(i=0;i < ASIZE; i++){
		if(coeff[i] == 0){
			continue;
		}
		
		char coef[ASIZE], expo[ASIZE];
		intToString(coef, coeff[i]);
		intToString(expo, exp[i]);
		
		if(exp[i] == 0){
			if(i == 0){
				StrgM(s, coef);
			}else{
				if(coeff[i] > 0){
					char temp[ASIZE] = "+";
					StrgM(temp,coef);
					StrgM(s, temp);
				}else{
					StrgM(s, coef);
				}
			}
		}else if(exp[i] == 1){
			if(i == 0){
				if(coeff[i] == 1){
					StrgM(s, "x");
				}else if(coeff[i] == -1){
					StrgM(s, "-x");
				}else{
					StrgM(s, coef);
					StrgM(s, "x");
				}
			}else{
				if(coeff[i] == 1){
					StrgM(s, "+x");
				}else if(coeff[i] == -1){
					StrgM(s, "-x");
				}else if(coeff[i] > 1){
					char temp[ASIZE] = "+";
					StrgM(temp,coef);
					StrgM(s, temp);
					StrgM(s, "x");
				}else{
					StrgM(s, coef);
					StrgM(s, "x");
				}
			}
		}else if(exp[i] > 1){
			if(i == 0){
				if(coeff[i] == 1){
					StrgM(s, "x^");
					StrgM(s, expo);
				}else if(coeff[i] == -1){
					StrgM(s, "-x^");
					StrgM(s, expo);
				}else{
					StrgM(s, coef);
					StrgM(s, "x^");
					StrgM(s, expo);
				}
			}else{
				if(coeff[i] == 1){
					StrgM(s, "+x^");
					StrgM(s, expo);
				}else if(coeff[i] == -1){
					StrgM(s, "-x^");
					StrgM(s, expo);
				}else if(coeff[i] > 1){
					char temp[ASIZE] = "+";
					StrgM(temp,coef);
					StrgM(s, temp);
					StrgM(s, "x^");
					StrgM(s, expo);
				}else{
					StrgM(s, coef);
					StrgM(s, "x^");
					StrgM(s, expo);
				}
			}
		}
	}

}  /* end polynom_to_string */

double power(double base, double exponent){
	double result = 1;
	while (exponent != 0)
    {
        result *= base;
        --exponent;
    }
	return result;
}

/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{

   int i;
   double temp = 0;
   for(i=0;i < ASIZE; i++){
		if(coeff[i] == 0){
			break;
		}
		
		temp += (coeff[i] * power(x, exp[i])); 
	}
	*result = temp;

}  /* end eval_polynom */



/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{
	int i, end, j, temp_ex,temp_co;
	for(i=0;i<ASIZE;i++){
		if(co1[i] == 0){
			end = i;
			break;}
	}
	
	for(i=0;i<ASIZE;i++,end++){
		if( co2[i] == 0){
			break;}
		co1[end] = co2[i];
		ex1[end] = ex2[i];
	}
	
    for(i=0;i<end;i++){
		for(j=i+1;j<end;j++){
			
			if(ex1[i] == ex1[j] && co1[i] != 0 && co1[j] != 0){
				co1[i] = co1[i] + co1[j];
				co1[j] = 0;
				ex1[j] = 0;
				if(co1[i] == 0){
					ex1[i] = 0;
				}
				i=-1;
				j=i+1;
				continue;
			}
			
			if(ex1[i] < ex1[j]){
				temp_co = co1[i];
				temp_ex = ex1[i];
				
				co1[i] = co1[j];
				ex1[i] = ex1[j];
				
				ex1[j] = temp_ex;
				co1[j] = temp_co;
			} else if(ex1[i] == ex1[j] && ex1[i] == 0 && (co1[j] > 0 || co1[j] < 0 )){
				temp_co = co1[i];
				temp_ex = ex1[i];
				
				co1[i] = co1[j];
				ex1[i] = ex1[j];
				
				ex1[j] = temp_ex;
				co1[j] = temp_co;
			} 
			
			
		}
	}
}  /* end add_ polynom */


/************************** END OF FILE ***************************/




