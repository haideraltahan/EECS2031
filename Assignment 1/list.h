/***********************************
* EECS2031 - Assignment 1		   
* Filename: list.h	  	
* Author: U. T. Nguyen
************************************/

typedef struct list {
   int data;
   struct list *next;
} List;


void prtError( char *errMsg );
void prtList();
List *init();
List *insertFirst( int d );
List *insertLast( int d );
int removeFirst();