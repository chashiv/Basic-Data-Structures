/*
	Calculates the prime factors any given number . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
void prime_factors(  int number );
int main()
{
	int number ;
	scanf("%d", &number);
	printf("%d = ",number);
	prime_factors(number);
	printf("\b\b ");
	return 0 ;
}

void prime_factors(  int number )
{
	int i = 2 ;
	if ( number == 1 )
	{
		return  ;
	}
	while( number % i != 0 )
		i++;
	printf("%d * ",i);
	prime_factors( number/i );
	
}