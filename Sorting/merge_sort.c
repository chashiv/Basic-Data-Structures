/*
   Author : Shivam Chauhan
   Date   : Feb 5 , 2019
   Implementation of Merge Sort
*/
#include <stdio.h>
#include <stdlib.h>

void merge_sort( int *arr , int beg , int end );
void merge( int *arr , int *tmp , int beg , int mid , int end );
void copy( int *arr , int *tmp , int beg , int end );
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
	merge_sort( arr , 0 , size - 1);
	display(arr);
	return 0 ;
}

void merge_sort( int *arr , int beg , int end )
{
	int mid = ( beg + end ) / 2 ; 
	int *tmp = ( int * ) malloc ( size * sizeof(int) ) ;
	if ( beg < end )
	{
		merge_sort( arr , beg , mid );
		merge_sort( arr , mid + 1 , end );
		merge( arr , tmp , beg , mid , end );
		copy( arr , tmp , beg , end );
	}
}

void merge( int *arr , int *tmp , int beg , int mid , int end )
{
	int i = beg , index = beg , j = mid + 1 ; 
	while ( i <= mid && j<= end )
	{
		tmp[ index++ ] = arr[i] < arr[j] ? arr[i++] : arr[j++] ; 
	}
	while ( i <= mid )
	{
		tmp[ index++ ] = arr [i++];
	}
	while ( j <= end )
	{
		tmp[ index++ ] = arr[j++];
	}
	copy( arr , tmp , beg , end );
}

void copy( int *arr , int *tmp , int beg , int end )
{
	int i;
	for ( i = beg ; i <= end ; i++ )
	{
		arr[i] = tmp[i];
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


