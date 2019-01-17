/*
    Recursively solve Tower Of Hanoi Problem . 
    Author : Shivam Chauhan . 
    Date : Jan 12 , 2019 .
*/
#include <stdio.h>
void tower_of_Hanoi(int rodCount , char fromRod , char toRod , char auxRod ) ;
int main()
{
    int n ;
    scanf("%d",&n);
    tower_of_Hanoi( n , 'A' , 'C' , 'B' );
    return 0;
}
void tower_of_Hanoi(int rodCount , char fromRod , char toRod , char auxRod )
{
    if (rodCount == 1)
    {
        printf("Move Rod %d : %c to %c.\n" , rodCount , fromRod , toRod );
        return ;
    }
    else
    {
        tower_of_Hanoi( rodCount - 1 , fromRod , auxRod , toRod);
        printf("Move Rod %d : %c to %c.\n" , rodCount , fromRod , toRod );
        tower_of_Hanoi( rodCount - 1 , auxRod , toRod , fromRod);
    }
}