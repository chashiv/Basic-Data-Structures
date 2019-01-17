/*
	Prints the number from 1 to n 
	Author : Shivam Chauhan
	Date : Jan 12 , 2019
*/
#include <stdio.h>
void print_n_void( int n );
int print_n_int( int n ) ;
int main()
{
	int n ;
	scanf("%d",&n);
	print_n_int(n);
	printf("\n");
	print_n_void(n);
	return 0 ;
}

void print_n_void( int n )
{
	if ( n == 0 )
		return ;
	print_n_void(n - 1);
	printf("%d ", n);
}

int print_n_int( int n )
{
	int num ;
	if ( n == 0 )
		return 0;
	num = print_n_int(n-1);
	printf("%d ", n);
	return num ;
}