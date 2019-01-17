/*
	Generates the fibonacci series . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
int fib( int n );
int main()
{
	int n , i ;
	scanf("%d",&n);
	for( i = 0 ; i < n ; i++ )
	{
		printf("%d ",fib( i ));	
	}
	return 0 ;
}
int fib( int n )
{
	if ( n == 0 || n == 1)
	{
		return 1;
	}
	return fib( n - 2 ) + fib( n - 1 ) ; 
}