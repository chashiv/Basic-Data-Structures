/*
	Calculates the exponent of the float number to a given +ve integer  . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
float exponent_calculator( float number , int power );
int main()
{
	float number ;
	int power ;
	scanf("%f %d",&number , &power);
	printf("%f",exponent_calculator(number , power));
	return 0 ;
}

float exponent_calculator( float number , int power )
{
	if ( power == 0 )
	{
		return 1;
	}
	return ( number * exponent_calculator( number , power - 1) ) ;
}