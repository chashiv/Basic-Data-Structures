#include<stdio.h>
#include<stdlib.h>
#include <string.h>

# define MAX 20

char stack[MAX] ;
int top = -1;

void push(char c);
char pop();
int is_full();
int is_empty();


int main()
{
  int ch ;
  unsigned int i ;
  char str[MAX] ;
  while (1)
  {
      printf("\nEnter the string (-1 to quit!!!) :");
      gets(str);
      for ( i = 0 ; i < strlen(str) ; i++ )
      {
        push(str[i]);
      }
      for ( i = 0 ; i < strlen(str) ; i++ )
      {
        str[i] = pop();
      }
      printf("\nReverse of the string is ");
      puts(str);
  }
  return 0;
}

int is_empty()
{
  return ( top == -1);
}

int is_full()
{
  return ( top == MAX - 1 );
}

void push(char val)
{
  if( is_full())
  {
      printf("\nStack Overflow!!!");
      return ;
  }
  else
  {
      stack[++top] = val ;
  }
}

char pop()
{
    char val ;
    if (is_empty())
    {
      printf("\nStack Underflow!!!");
      exit(1);
    }
    else
    {
      return stack[top--];
    }
}
