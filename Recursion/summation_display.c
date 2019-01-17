/*
	Prints the sum of the number in 1 + 2 + 3 .....n format . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
int rseries( int n );
int main()
{
	int n ;
	scanf("%d",&n);
	printf("\b\b\b = %d ",rseries(n));
	return 0 ;
}

int rseries( int n )
{
	int sum ;
	if ( n == 0 )
		return 0;
	sum =  n + rseries( n - 1);
	printf("%d + ", n);
	return sum ;
}