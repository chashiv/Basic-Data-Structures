#include<stdio.h>
#include<stdlib.h>

# define MAX 5

int arr[MAX] , top = -1;

void push(int);
int pop();
int isFull();
int isEmpty();
void disp();


int main()
{
  int ch , val , popped_val;
  while(1)
  {
        printf("\n\t\t-------------------------STACK------------------------\n");
        printf("\n\t\t1.PUSH\n\t\t2.POP\n\t\t3.DISPLAY\n\t\t4.EXIT");
        printf("\nEnter your choice :");
        scanf("%d",&ch );
        switch( ch )
        {
          case 1 :  printf("\nEnter the value to be pushed ");
                    scanf("%d", &val);
                    push(val);
                    break;

          case 2 :  if( isEmpty())
                    {
                        printf("\nStack Underflow!!!" );                      
                    }
                    else
                    {
                        popped_val = pop();
                        printf("\nThe popped value is %d .", popped_val );                      
                    }
                    break ;

          case 3 :  if( isEmpty())
                    {
                        printf("\nStack Underflow!!!" );                      
                    }
                    else
                    {
                        disp();              
                    }
                    break ;

          default : exit(0) ;
                    break ; 
        }
        
    }
  return 0;
}

int isFull()
{
  if (top ==  MAX -1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if (top == -1)
    return 1;
  else
    return 0;
}

void push(int val)
{
  if(!isFull())
  {
    arr[++top] = val;
    printf("\n%d is pushed on the stack .",val);
  }
  else
    printf("\nStack Overflow!!!");
}

int pop()
{
    int val ;
    val = arr[top];
    top--;
    return val;
}


void disp()
{
      int i;
      for( i = top ; i >= 0 ; i--)
      {
        printf("%d ",arr[i]);
      }
}
