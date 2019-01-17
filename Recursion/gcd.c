/*
	Calculates the Greatest Common factor of any given number . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
int gcd(  int divisor , int number );
int main()
{
	int number1 , number2 , result ;
	scanf("%d %d", &number1 , &number2 ) ;
	result = number1 < number2 ? gcd( number1 , number2 ) : gcd( number2 , number1 ) ;
	printf("GCD of %d and %d is :  %d", number1 , number2 ,  result);
	return 0 ;
}

int gcd(  int divisor , int number )
{
	int remainder = number % divisor ;
	return ( remainder == 0 ? divisor : gcd( remainder , divisor ) ) ;
}