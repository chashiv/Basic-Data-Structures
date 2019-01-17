/*
	Prints the sum of digits of the number and displays the digits . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
int sum_of_digits( int n );
int main()
{
	int n ;
	scanf("%d",&n);
	printf("\b\b\b = %d " ,sum_of_digits( n ) );
	return 0;
}

int sum_of_digits( int n )
{
	int sum ;
	if ( n / 10 == 0 )
	{
		printf("%d + ", n);
		return n ;
	}
	sum = ( n % 10 ) + sum_of_digits( n / 10 );
	printf("%d + ", n % 10 );
	return sum ;
}