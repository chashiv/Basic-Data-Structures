/*
	Converts the decimal number into the specified form . 
	Author : Shivam Chauhan . 
	Date : Jan 12 , 2019 .
*/
#include <stdio.h>
void base_conversion( int base , int number );
int main()
{
	int base , number ;
	scanf("%d %d",&base , &number);
	base_conversion(base , number);
	return 0 ;
}

void base_conversion( int base , int number )
{
	int rem = number % base ;
	if ( number == 0 )
	{
		return ;
	}
	base_conversion( base , number / base);
	if ( rem < 10 )
	{
		printf("%d",rem);
	}
	else
	{
		printf("%c",rem-10+'A');			
	}
}