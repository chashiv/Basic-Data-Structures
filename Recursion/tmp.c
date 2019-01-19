#include <stdio.h>
void print_1_3( int n );
int main() 
{
    int n;
    scanf("%d",&n);
    print_1_3(n);
	return 0;
}
void print_1_3( int n )
{
    int digit , flag = 0;
    if ( n == 0)
    {
        return ;
    }
    while( n > 0 )
    {
        digit = n % 10 ;
        if ( digit == 1 || digit == 3)
        {
           flag = 1;
           break;
        }
        n /= 10 ;
    }
    if (flag == 1)
    {
        printf("%d",n);
    }
    print_1_3( n - 1 );
}