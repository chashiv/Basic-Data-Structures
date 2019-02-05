/*
   Author : Shivam Chauhan
   Date   : Feb 5 , 2019
   Implementation of Counting Sort
*/
#include <stdio.h>
#include <stdlib.h>

void count_sort( int *array , int *auxiliary );
void display( int *arr);

int size , max = -999999 ;

int main()
{
	int i ;
	printf("\nEnter the size of the array ");
	scanf("%d",&size);
	int *array = ( int * ) malloc ( size * sizeof( int ) );
	int *auxiliary = ( int * ) calloc ( size , sizeof( int ) );
	for ( i = 0 ; i < size ; i++ )
	{
		scanf("%d",&array[i]);
		max = array[i] > max ? array[i] : max ;
	}
	count_sort( array , auxiliary );
	display(auxiliary);
	return 0 ;
}

void count_sort( int *array , int *auxiliary )
{
	int i ;
	int *frequency = ( int * ) calloc ( max + 1 , sizeof( int ) );
	// Calculating the frequency of each number +
	for ( i = 0 ; i < size ; i++ )
	{
		frequency [ array [ i ] ] ++ ; 
	}
	// Calculating the Cumulative Frequency
	for ( i = 1 ; i <= max  ; i++ )
	{
		frequency [ i ] = frequency [ i ] + frequency [ i - 1 ];
	}
	for ( i = size - 1 ; i >= 0 ; i-- )
	{
		auxiliary [ frequency [ array[ i ] ] - 1 ] = array [ i ] ;
		frequency [ array [ i ] ] -- ;  
	}
}

void display( int *arr)
{
	int i ;
	printf("\nSorted Elements are : \n");
	for ( i = 0 ; i < size ; i++ )
	{
		printf("%d ",arr[i]);
	}
}


