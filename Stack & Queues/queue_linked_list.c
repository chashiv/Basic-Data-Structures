
/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Queue(Using Linked List) Implementation
*/
#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int info ;
	struct queue *link ;
} *front = NULL , * rear = NULL ;

int size = 0 ;
int is_empty();
void enqueue(int element);
int dequeue();
int peek();
void display();
void clear();

int main()
{
	int choice , element ;
	while(1)
  	{
            if(!is_empty())
                printf("\nFront : %d || Rear : %d", front -> info , rear -> info );
            else
                printf("\nFront : NULL || Rear : NULL");
            printf("\n\t\t----------------------------------------------------------------\n") ;
            printf("\n\t\t\t\t\tQueue Using Linked List \n\t\t\t\t----------------------------------") ;
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
      		                scanf("%d",&element); 
            		          enqueue(element);
            		          break;

              	case 2 :  if (!is_empty())
                          {
                              printf("\nThe dequeued element is %d ",dequeue());
                          }
                          else
                          {
                              printf("\nQueue Underflow!!!");
                          }
                          break;

                case 3 :  if (!is_empty())
                          {
                              printf("\nThe peeked element is %d ",peek());
                          }
                          else
                          {
                              printf("\nQueue Underflow!!!");
                          }
                          break;

                case 4 :  if (!is_empty())
                          {
                              display();
                          }
                          else
                          {
                              printf("\nQueue Underflow!!!");
                          }
                          break;

                case 5 :  if (!is_empty())
                          {
                              clear();
                          }
                          else
                          {
                              printf("\nQueue Underflow!!!");
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

void enqueue( int element )
{
	struct queue *tmp ;
	tmp = (struct queue*)malloc(sizeof(struct queue)) ;
	tmp -> info = element ;
      tmp -> link = NULL ;	
      if ( front == NULL )
      {
            front = tmp ;
      }
      else
      {
      	rear -> link = tmp ;  
      }
      rear = tmp ;
	size++;
	printf("\n%d is enqueued on the queue ",element);
}

int dequeue()
{
	int element ;
	struct queue *tmp = front ;
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
	struct queue *tmp = front ;
	for( tmp = front ; tmp != NULL ; tmp = tmp -> link )
	{
		printf("%d ",tmp -> info);
	}
}
void clear()
{
	struct queue *tmp = front ;
	while( front != NULL )
	{
		tmp = front ;
		front = front -> link ;
		size --;
		free(tmp);
	}
	printf("\nQueue is cleared!!!");
}