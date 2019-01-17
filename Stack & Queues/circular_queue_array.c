#include<stdio.h>
#include<stdlib.h>
# define MAX 5

int arr[MAX] , front = -1 , rear = -1 ;

void enqueue(int);
int dequeue();
int is_full();
int is_empty();
void disp();


int main()
{
  int ch , val , popped_val;
  while(1)
  {
        printf("\n\t\t----------------------CIRCULAR QUEUE------------------------\n");
        printf("\n\t\t1.ENQUEUE\n\t\t2.DEQUEUE\n\t\t3.DISPLAY\n\t\t4.EXIT");
        printf("\nFront = %d || Rear = %d \n",front , rear );
        printf("\nEnter your choice :");
        scanf("%d",&ch );
        switch( ch )
        {
          case 1 :  printf("\nEnter the value to be enqueued ");
                    scanf("%d", &val);
                    enqueue(val);
                    break;

          case 2 :  if( is_empty() )
                    {
                        printf("\nCircular Queue Underflow!!!" );                      
                    }
                    else
                    {
                        popped_val = dequeue();
                        printf("\nThe dequeued value is %d .", popped_val );                      
                    }
                    break ;

          case 3 :  if( is_empty() )
                    {
                        printf("\nCircular Queue Underflow!!!" );                      
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

void enqueue(int val)
{
  if(!is_full())
  {
      if ( front == -1 )
      {
        front = 0 ;
      }
      else
      {
        rear = ( rear + 1 ) % MAX ;
      }
      arr[ rear ] = val ;
      printf("\n%d is enqueued on the circular queue .",val);
  }
  else
    printf("\nCircular Queue Overflow!!!");
}

int dequeue()
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


void disp()
{
      int i;
      for( i = front ; i != rear ; i = ( i + 1 ) % MAX )
      {
        printf("%d ",arr[i]);
      }
      printf("%d ",arr[i]);
}
