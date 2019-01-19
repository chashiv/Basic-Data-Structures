/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Parentheses Matching

Examples : 
      '[A-B*(C+D)'     : invalid
      '(1+5}'          : invalid
      '[5+4*(9-2)]'    : valid
      '[A+B-(C%D}]'    : invalid
      '[A/(B-C)*D]'    : valid

*/
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
int is_matched( char a , char b );
int parentheses_matcher(char str[]);
int main()
{
    int matched , choice , i ;
    char str[MAX] ;
    while(1)
    {
              printf("\n\t\t----------------------Parentheses Matcher----------------------") ;
              printf("\n\t\t\t\t1.  Match ") ;
              printf("\n\t\t\t\t2.  Exit ") ;
              printf("\n\t\tEnter the choice  : ") ;
              scanf("%d",&choice);
              switch( choice )
              {
                  case 1 :  printf("\nEnter the expression :") ;
                            scanf("%s",&str);
                            matched = parentheses_matcher(str);
                            if (matched)
                            {
                                printf("\nParentheses are balanced. ") ;
                            }
                            break;

                 default :  exit(1);
                            break;
              }
          
          top = -1 ;
          for ( i = 0 ; i < strlen(stack) ; i++ )
          {
            stack[i] = '\0';
          }
          for ( i = 0 ; i < strlen(str) ; i++ )
          {
            str[i] = '\0';
          } 
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

int is_matched( char a , char b )
{
    if ( a == '[' && b == ']' )
        return 1;
    if ( a == '{' && b == '}' )
        return 1;
    if ( a == '(' && b == ')' )
        return 1;
    else
        return 0 ;
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

int parentheses_matcher( char str[] )
{
    int i ;
    char popped_val ;
      for ( i= 0 ; i < strlen(str) ; i++ )
      {
          if ( str[i] == '[' || str[i] == '{' || str[i] == '(' )
          {
              push(str[i]);
          }
          else
          {
              if( str[i] == ']' || str[i] == '}' || str[i] == ')' )
              {
                  if ( is_empty() )
                  {
                      printf("\nRight parentheses are more!!!");
                      return 0 ;                      
                  }
                  else
                  {
                      popped_val = pop();
                      if( !is_matched( popped_val , str[i]) )
                      {
                          printf("\nMismatched parentheses %c and %c.", popped_val , str[i]);
                          return 0 ;                      
                      }
                  }
              }

          }

      }
      if ( is_empty () )
      {
          return 1 ;
      }
      else if ( !is_empty() )
      {
          printf("\nLeft parentheses are more!!!");
          return 0 ;
      }
}
