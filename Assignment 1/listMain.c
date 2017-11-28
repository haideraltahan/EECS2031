/***********************************
* EECS2031 - Assignment 1		   
* Filename: listMain.c	  	
* Author: U. T. Nguyen
************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

main()
{
   List *p;
   int i;

   if ( (p = (List *) init()) == NULL )
	exit( 1 );

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) insertLast( i*5 )) == NULL )
	   exit( 1 );
	prtList();
   }

   while ( removeFirst() > 0 )
      	prtList();
		
   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) insertFirst( i*5 )) == NULL )
	   exit( 1 );
	prtList();
  }

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) search( i*4 )) )  
	   printf( "search %d found %d\n", i*4, p->data );
	else
	   printf( "search %d not found\n", i*4 );
   }
}

