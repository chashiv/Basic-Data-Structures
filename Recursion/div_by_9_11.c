/*
	Checks for the divisibility by 9 or 11 . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
int sum( int n );
int main()
{
	int n ;
	scanf("%d",&n);
	printf("SUM = %d\n",sum(n));
	sum(n) %  9 == 0 ? printf("%d is divisible by 9\n" , n )   : printf("%d is not divisible by 9.\n" , n ) ;  
	sum(n) % 11 == 0 ? printf("%d is divisible by 11.\n" , n ) : printf("%d is not divisible by 11.\n" , n ) ;  	
	return 0 ;
}
int sum ( int n )
{
	if ( n / 10 == 0 )
	{
		return n ;
	}
	return ( n % 10 + sum( n/10 ) ) ;
}