/*
   Author : Shivam Chauhan
   Date   : Feb 5 , 2019
   Implementation of Shell Sort
*/

#include <stdio.h>
#include <stdlib.h>

int get_h();
void shell_sort( int *arr);
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
	shell_sort(arr);
	display(arr);
	return 0 ;
}
int get_h()
{
	int increment;
	while( increment <= (size-1)/9 )
	{
		increment = increment * 3 + 1;
	}
	return increment ;
}

void shell_sort( int *arr)
{
	int increment = get_h() , key , i , j ;
	while( increment >= 1 )
	{
		for ( i = increment ; i < size ; i = i + increment )
		{
			key = arr [i];
			j = i - increment ;
			while ( j >= 0 && key < arr[j] )
			{
				arr[ j + increment ] = arr [j] ;
				j = j - increment ;
			}
			arr[ j + increment ] = key ;
		}
		increment = increment / 3 ;
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


