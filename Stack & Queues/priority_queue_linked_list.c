#include <stdio.h>
#include <stdlib.h>
struct priority_queue
{
  int priority ; 
	int info ;
	struct priority_queue *link ;
} *front = NULL ;

int size = 0 ;
int is_empty();
void enqueue( int element , int priority );
int dequeue();
int peek();
void display();
void clear();

int main()
{
	int choice , element , priority ;
	while(1)
  	{
            printf("\n\t\t----------------------------------------------------------------\n") ;
            printf("\n\t\t\t\tPriority Queue Using Linked List \n\t\t\t\t----------------------------------") ;
            printf("\n\t\t\t\t1.  Push ") ;
            printf("\n\t\t\t\t2.  Pop ") ;
            printf("\n\t\t\t\t3.  Peek ") ;
            printf("\n\t\t\t\t4.  Display ") ;
            printf("\n\t\t\t\t5.  Clear ") ;
            printf("\n\t\t\t\t6.  Count ") ;      
            printf("\n\t\t\t\t7.  Exit ");
            printf("\n\t\t\t\t\nEnter your Choice : ") ;
            scanf("%d",&choice);	
            switch(choice)
            {

              	case 1 :  printf("\nEnter the element :");
      		                scanf("%d", &element ); 
                          printf("\nEnter the priority of the element :");
                          scanf("%d", &priority ); 
            		          enqueue( element , priority );
            		          break;

              	case 2 :  if (!is_empty())
                          {
                              printf("\nThe dequeued element is %d ",dequeue());
                          }
                          else
                          {
                              printf("\nPriority Queue Underflow!!!");
                          }
                          break;

                case 3 :  if (!is_empty())
                          {
                              printf("\nThe peeked element is %d ",peek());
                          }
                          else
                          {
                              printf("\nPriority Queue Underflow!!!");
                          }
                          break;

                case 4 :  if (!is_empty())
                          {
                              display();
                          }
                          else
                          {
                              printf("\nPriority Queue Underflow!!!");
                          }
                          break;

                case 5 :  if (!is_empty())
                          {
                              clear();
                          }
                          else
                          {
                              printf("\nPriority Queue Underflow!!!");
                          }
                          break;

                case 6 :  printf("\nThere are %d elements ",size);
                          break;

                default : exit(0);
                          break;

            }
     }
     return 0;
}

int is_empty()
{
	return ( front == NULL );
}

void enqueue( int element , int priority  )
{
      struct priority_queue *tmp , * p ;
      tmp = (struct priority_queue*)malloc(sizeof(struct priority_queue)) ;
      tmp -> info = element ;
      tmp -> priority = priority ;
      if ( is_empty() || tmp -> priority <  front -> priority ) 
      {
            tmp -> link = front ;
            front = tmp ;
      }
      else
      {
          for( p = front ; p -> link != NULL && p -> link -> priority  <=  priority ;  )
          {
                p = p -> link ;
          }

          tmp -> link = p -> link ;
          p -> link = tmp ;
      }
	    size++ ;
    	printf("\n%d is enqueued on the queue ",element);
}

int dequeue()
{
    int element ;
    struct priority_queue *tmp = front ;
    element = tmp -> info ;
    front = front -> link ;
    free(tmp);
    size -- ;
    return element ;
}

int peek()
{
  	return front -> info ;
}

void display()
{
  	struct priority_queue *tmp = front ;
  	for( tmp = front ; tmp != NULL ; tmp = tmp -> link )
  	{
  		printf("%d ",tmp -> info);
  	}
}

void clear()
{
  	struct priority_queue *tmp = front ;
  	while( front != NULL )
  	{
  		tmp = front ;
  		front = front -> link ;
  		size --;
  		free(tmp);
  	}
  	printf("\nPriority Queue is cleared!!!");
}