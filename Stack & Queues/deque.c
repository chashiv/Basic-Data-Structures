/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Circular Queue Implementation
*/
#include<stdio.h>
#include<stdlib.h>

# define MAX 7

int arr[MAX] , front = -1 , rear = -1 ;

void enqueue_front_end(int);
void enqueue_rear_end(int);
int dequeue_front_end();
int dequeue_rear_end();
int is_full();
int is_empty();
void disp();


int main()
{
  int ch , val , popped_val;
  while(1)
  {
        printf("\n\t\t---------------------------DEQUE------------------------\n");
        printf("\n\t\t1.ENQUEUE FRONT END \n\t\t2.ENQUEUE BACK END\n\t\t3.DEQUEUE FRONT END \n\t\t4.DEQUEUE BACK END"
        "\n\t\t5.DISPLAY\n\t\t6.EXIT");
        printf("\nFront = %d || Rear = %d \n",front , rear );
        printf("\nEnter your choice :");
        scanf("%d",&ch );
        switch( ch )
        {
          case 1 :  printf("\nEnter the value to be enqueued ");
                    scanf("%d", &val);
                    enqueue_front_end(val);
                    break;

          case 2 :  printf("\nEnter the value to be enqueued ");
                    scanf("%d", &val);
                    enqueue_rear_end(val);
                    break;

          case 3 :  if( is_empty() )
                    {
                        printf("\nDeque Underflow!!!" );                      
                    }
                    else
                    {
                        popped_val = dequeue_front_end();
                        printf("\nThe dequeued value is %d .", popped_val );                      
                    }
                    break ;

          case 4 :  if( is_empty() )
                    {
                        printf("\nDeque Underflow!!!" );                      
                    }
                    else
                    {
                        popped_val = dequeue_rear_end();
                        printf("\nThe dequeued value is %d .", popped_val );                      
                    }
                    break ;

          case 5 :  if( is_empty() )
                    {
                        printf("\nDeque Underflow!!!" );                      
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

int is_full()
{
  if ( ( front == 0 && rear == MAX - 1 ) || front == rear + 1 )
    return 1;
  else
    return 0;
}

int is_empty()
{
  if ( front == -1 )
    return 1;
  else
    return 0;
}

void enqueue_front_end(int val)
{
  if(!is_full())
  {
      if ( front == -1 )
      {
        front = 0 ;
        rear = 0 ;
      }
      else
      {
        front = ( front + MAX -1 ) % MAX  ;
      }
      arr[ front ] = val ;
      printf("\n%d is enqueued on the deque .",val);      
  }
  else
    printf("\nDeque Overflow!!!");
}

void enqueue_rear_end(int val)
{
  if(!is_full())
  {
      if ( front == -1 )
      {
        front = 0 ;
        rear = 0 ;
      }
      else
      {
        rear = ( rear + 1 ) % MAX ;
      }
      arr[ rear ] = val ;
      printf("\n%d is enqueued on the deque .",val);
  }
  else
    printf("\nDeque Overflow!!!");
}

int dequeue_front_end()
{
    int val ;
    val = arr[front];
    if ( front == rear )
    {
      front = rear = -1;
    }
    else
      front = ( front + 1) % MAX ;
    return val;
}

int dequeue_rear_end()
{
    int val ;
    val = arr[rear];
    if ( front == rear )
    {
      front = rear = -1;
    }
    else
    {
      rear = ( rear + MAX - 1 ) % MAX ;
    }
    return val;
}


void disp()
{
      int i;
      for( i = front ; i != rear ; i = ( i + 1 ) % MAX )
      {
        printf("%d ",arr[i]);
      }
      printf("%d ",arr[i]);
}
