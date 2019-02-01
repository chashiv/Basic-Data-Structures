/*
   Author : Shivam Chauhan
   Date   : Feb 1 , 2019
   Implementation of Selection Sort
*/
#include <stdio.h>
#include <stdlib.h>
void selection_sort( int *arr);
void display( int *arr);
int size ;
int main()
{
	int i ;
	printf("\nEnter the size of the array ");
	scanf("%d",&size);
	int *arr = (int *)malloc( size * sizeof(int));
	for ( i = 0 ; i < size ; i++ )
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr);
	display(arr);
}
void selection_sort( int *arr)
{
	int i , j , min , tmp ;
	for ( i = 0 ; i < size - 1 ; i++ )
	{
		min = i;
		for ( j = i + 1 ; j < size ; j++ )
		{
			if ( arr[min] > arr [j] ) 
			{
				min = j ;
			}
		}
		if ( i != min )
		{
			tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp ;
		}
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


