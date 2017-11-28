/***********************************
 * EECS 2031 - Assignment 2
 * Filename: mm.c
 * Author: Al-Tahan,Haider
 * Email: haideraltahan@gmail.com
 * Login ID: mrfirete
 ************************************/


#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

/* You may define additional functions and local variables. */
int convertToInt(char* c){
    int s = 1;
    int i = -1;
    int res = 0;
    if (*(c) == '-') {
        s = -1;
        i = 0;
    }
    while (*(c+(++i)) != '\0') {
        res = res*10 + (*(c+i) - '0');
    }
    return res*s;
}

/*
 Save the three command-line arguments into nr1, nc1 and nc2.
 */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{
    *nr1 = convertToInt(*(argv+1));
    *nc1 = convertToInt(*(argv+2));
    *nc2 = convertToInt(*(argv+3));
}




/*
 Initialize a 2-dimensional array.
 Element (i, j) is assigned value i+j.
 */

void initMatrix ( int **a, int nrows, int ncols )
{
    int i, j;
    for(i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            *(*(a+i)+j) = i + j;
        }
    }
}





/*
 Multiply arrays a and b.
 Array a has nr1 rows and nc1 columns.
 Array b has nc1 rows and nc2 columns.
 Allocate an array c having nr1 rows and nc2 columns.
 Compute a x b and store the result in array c.
 Return array c.
 If an error occurs (e.g., insufficient memory), return NULL pointer.
 */


int **matrix_mult( int **a, int **b, int nr1, int nc1, int nc2 )
{
    
    int **c, i, j, k, f;
    /* Allocate an array of pointers, each pointing to a row. */
    c = ( int** ) malloc( nr1 * sizeof( int* ) );
    if ( c == NULL ) {
        printf( "Insufficient memory!\n" );
        return NULL;
    }
    
    /* Allocate each row. */
    for(i = 0; i < nr1; i++) {
        *(c+i) = ( int* ) malloc( nc2 * sizeof( int ) );
        if ( *(c+i) == NULL ) {
            printf( "Insufficient memory!\n" );
            return NULL;
        }
    }
    
    
    for (i = 0; i < nr1; i++)
    {
        for (j = 0; j < nc2; j++)
        {
            *(*(c+i)+j) = 0;
	    for( k = 0; k < nc1; k++){
		*(*(c+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
	    }
        }
    }
    
    return( c );    /* replace this line with your code */
}



/************************* END OF FILE *************************/

