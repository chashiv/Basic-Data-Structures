/*
	Prints the number in normal and reverse order . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
void print_normal( int n );
void print_reverse( int n ) ;
int main()
{
	int n ;
	scanf("%d",&n);
	print_normal(n);
	printf("\n");
	print_reverse(n);
	return 0 ;
}

void print_normal( int n )
{
	int digit ;
	if ( n / 10 == 0 )
	{
		printf("%d",n);
		return ;		
	}
	digit = n % 10 ;
	print_normal(n / 10 );
	printf("%d", digit);
}

void print_reverse( int n )
{
	int num ;
	if ( n / 10  == 0 )
	{
		printf("%d",n);
		return ;
	}
	printf("%d", n % 10);
	print_reverse( n / 10);
}