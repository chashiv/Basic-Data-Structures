/*
   Author : Shivam Chauhan
   Date   : Feb 5 , 2019
   Implementation of Radix Sort
*/
#include <stdio.h>
#include <stdlib.h>

void radix_sort( int *array , int *auxiliary );
void display( int *arr);

int size , max = - 9999999;

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
	printf("%d\n", max);
	radix_sort( array , auxiliary );
	display(array);
	return 0 ;
}

void radix_sort( int *array , int *auxiliary )
{
	int digit_place = 1 , i ;
	// Max is largest number present in an array
	while( max / digit_place > 0 )
	{
		int *frequency = ( int * ) calloc ( 10 , sizeof( int ) );
		// Calculating the frequency of each number +
		for ( i = 0 ; i < size ; i++ )
		{
			frequency [ ( array [ i ] / digit_place ) % 10 ] ++ ; 
		}
		// Calculating the Cumulative Frequency
		for ( i = 1 ; i <= 9  ; i++ )
		{
			frequency [ i ] = frequency [ i ] + frequency [ i - 1 ];
		}
		for ( i = size - 1 ; i >= 0 ; i-- )
		{
			auxiliary [ frequency [ ( array [ i ] / digit_place ) % 10 ] - 1 ] = array [ i ] ;
			frequency [ ( array [ i ] / digit_place ) % 10 ] -- ;  
		}
		for ( i = 0 ; i < size ; i++ )
		{
			array [ i ] = auxiliary [ i ] ; 
		}
		digit_place *= 10 ;	
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


