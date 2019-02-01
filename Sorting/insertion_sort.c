/*
   Author : Shivam Chauhan
   Date   : Feb 2 , 2019
   Implementation of Insertion Sort
*/
#include <stdio.h>
#include <stdlib.h>
void insertion_sort( int *arr);
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
	insertion_sort(arr);
	display(arr);
	return 0 ;
}
void insertion_sort( int *arr)
{
	int i , j , tmp , key  ;
	for ( i = 1 ; i < size ; i++ )
	{
		key = arr[i] ;
		j = i - 1 ;
		while ( j >= 0 && key < arr[j] )
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key ;
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


