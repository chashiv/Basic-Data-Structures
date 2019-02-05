/*
   Author : Shivam Chauhan
   Date   : Feb 5 , 2019
   Implementation of Quick Sort
*/
#include <stdio.h>
#include <stdlib.h>

void quick_sort( int *arr , int beg , int end );
int partition( int *arr, int beg , int end );
void display( int *arr);

int size ;

int main()
{
	int i ;
	printf("\nEnter the size of the array ");
	scanf("%d",&size);
	int *arr = ( int * ) malloc ( size * sizeof(int) );
	for ( i = 0 ; i < size ; i++ )
	{
		scanf("%d",&arr[i]);
	}
	quick_sort( arr , 0 , size - 1 );
	display(arr);
	return 0 ;
}

void quick_sort( int *arr , int beg , int end )
{
	if ( beg < end )
	{
		int pivot_loc = partition( arr , beg , end );
		quick_sort( arr , beg ,  pivot_loc - 1 );
		quick_sort( arr , pivot_loc + 1 , end );
	}
}

int partition( int *arr , int beg , int end )
{
	int i = beg + 1 , j = end , pivot = arr[beg] , tmp ;
	while ( i <= j )
	{
		while( arr[i] < pivot && i <= end )
		{
			i++;
		}
		while( arr[j] > pivot )
		{
			j--;
		}
		if ( i < j )
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp ;
			i++;
			j--;
		}
		else
			i++;
	}
	arr[beg] = arr[j];
	arr[j] = pivot ;
	return j ;
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


