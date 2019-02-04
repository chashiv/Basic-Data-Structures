/*
   Author : Shivam Chauhan
   Date   : Feb 4 , 2019
   Heap Implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int is_empty(int heap_size);
int get_parent ( int i ) ;
void insert ( int data , int arr[] , int *heap_size ) ;
void restore_up( int arr[] , int location );
int delete( int arr[] , int *heap_size);
void restore_down( int arr[] , int location , int heap_size);
void build_heap( int arr[] , int heap_size);
void display( int arr[] , int heap_size);

int main()
{
  int ch , val , heap_size = 0 ;
  int arr[MAX] ;
  while(1)
  {
        printf("\n\t\t-------------------------HEAP------------------------\n");
        printf("\n\t\t1.INSERT\n\t\t2.DELETE\n\t\t3.DISPLAY\n\t\t4.EXIT");
        printf("\nEnter your choice :");
        scanf("%d",&ch );
        switch( ch )
        {
          case 1 :  printf("\nEnter the value to be inserted ");
                    scanf("%d", &val);
                    insert( val , arr , &heap_size) ;
                    break;

          case 2 :  if( is_empty(heap_size))
                    {
                        printf("\nHeap is Empty!!!" );                      
                    }
                    else
                    {
                        printf("\nThe deleted value is %d ", delete( arr , &heap_size) );                      
                    }
                    break ;

          case 3 :  if( is_empty(heap_size))
                    {
                        printf("\nHeap is Empty!!!" );                                           
                    }
                    else
                    {
                        display(arr,heap_size);              
                    }
                    break ;

          default : exit(0) ;
                    break ; 
        }
        
    }
  return 0;
}

int is_empty(int heap_size)
{
	return heap_size == 0 ;
}

int get_parent( int i )
{
	/* if index starts with 0 
	:	    parent = floor(i-1)/2
	:	left child = 2*i+1
	:  right child = 2*i+2
	*/
	return ( i ) / 2 ;
}

void insert ( int data , int arr[] , int *heap_size )
{
	(*heap_size)++;
	arr[ *heap_size ] = data ;
	restore_up( arr , *heap_size);
}

void restore_up ( int arr[] , int i )
{
	int key = arr[i];
	int parent = get_parent(i) ;
	while ( parent >= 1 && arr[parent] < key )
	{
		arr[i] = arr[parent];
		i = parent ;
		parent = get_parent(i);
	}
	arr[i] = key ;
}

int delete ( int arr[] , int *heap_size)
{
	int max = arr[1];
	arr[1] = arr[*heap_size] ;
	(*heap_size)--;
	restore_down ( arr , 1 , *heap_size );
	return max;
}

void restore_down ( int arr[] , int i , int heap_size )
{
	int left_child = 2 * i , right_child = left_child + 1;
	int data = arr[1];
	// printf("LC = %d || RC = %d || HS = %d || Data = %d ", left_child , right_child ,heap_size,data) ;
	while ( right_child <= heap_size )
	{
		if ( data >= arr[left_child] && data >= arr[right_child] )
		{
			arr[i] = data ;
			return ;
		}
		else if ( arr[left_child] > arr[right_child] )
		{
			arr[i] = arr[left_child] ;
			i = left_child ;
		}
		else
		{
			arr[i] = arr[right_child] ;
			i = right_child ;
		}
		left_child = 2 * i ;
		right_child = left_child + 1 ;
	}
	if ( ( left_child == heap_size ) && ( data < arr[left_child]) )
	{
		arr[i] = arr[left_child] ;
		i = left_child ;
	}
	arr[i] = data ;
}

void build_heap ( int arr[] , int heap_size)
{
	int i ;
	for ( i = 2 ; i <= heap_size ; i++ )
	{
		restore_up(arr,i);
	}
}

void display( int arr[] , int heap_size )
{
	int i ;
	for( i = 1 ; i <= heap_size ; i++ )
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}