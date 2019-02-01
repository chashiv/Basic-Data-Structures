/*
   Author : Shivam Chauhan
   Date   : Feb 2 , 2019
   Implementation of Bubble Sort
*/
#include <stdio.h>
#include <stdlib.h>
void bubble_sort( int *arr);
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
	bubble_sort(arr);
	display(arr);
	return 0 ;
}
void bubble_sort( int *arr)
{
	int i , j , tmp , swap_count = 0 ;
	for ( i = 0 ; i < size ; i++ )
	{
		for ( j = 0 ; j < size - 1 - i ; j++ )
		{
			if ( arr [ j ] > arr [ j + 1] ) 
			{
				tmp = arr [j] ;
				arr[j] = arr[j+1];
				arr[j+1] = tmp ;
				swap_count++;
			}
		}
		if ( !swap_count )
			break;
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


