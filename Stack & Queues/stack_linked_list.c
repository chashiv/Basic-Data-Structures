/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Stack (Using Linked List) Implementation
*/

#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int info ;
	struct stack *link ;
} *top = NULL ;

int size = 0 ;
int is_empty();
void push(int element);
int pop();
int peek();
void display();
void clear();

int main()
{
	int choice , element ;
	while(1)
  	{
            printf("\n\t\t----------------------------------------------------------------\n") ;
            printf("\n\t\t\t\t\tStack Using Linked List \n\t\t\t\t----------------------------------") ;
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
      			   push(element);
      			   break;

      	     case 2 :  if (!is_empty())
      			   {
      				printf("\nThe deleted element is %d ",pop());
      			   }
      			   else
      				printf("\nStack is Empty!!!");
      			
      			   break;

      	     case 3 : if (!is_empty())
      			   {
      				printf("\nThe peeked element is %d ",peek());
      			   }
      			   else
      				printf("\nStack is Empty!!!");
      			   break;
      			
      	     case 4 : if (!is_empty())
      			   {
      				display();
      			   }
      			   else
      				printf("\nStack is Empty!!!");
      			   break;

      	     case 5 : if (!is_empty())
      			   {
      				clear();
      			   }
      			   else
      				printf("\nStack is Empty!!!");
      			   break;

      	     case 6 : printf("\nThere are %d elements ",size);
      			  break;

      	    default : exit(0);
      			  break;

            }
      }
	return 0;
}

int is_empty()
{
	return (top == NULL);
}

void push( int element )
{
	struct stack *tmp ;
	tmp = (struct stack*)malloc(sizeof(struct stack)) ;
	tmp -> info = element ;
	tmp -> link = NULL ;	
	tmp -> link = top ;
	top = tmp ;
	size++;
	printf("\n%d is pushed on the stack ",element);
}

int pop()
{
	int element ;
	struct stack *tmp = top ;
	element = tmp -> info ;
	top = top -> link ;
	free(tmp);
	size -- ;
	return element ;
}

int peek()
{
	return top -> info ;
}
void display()
{
	struct stack *tmp = top ;
	for( tmp = top ; tmp != NULL ; tmp = tmp -> link )
	{
		printf("%d ",tmp -> info);
	}
}
void clear()
{
	struct stack *tmp = top ;
	while( top != NULL )
	{
		tmp = top ;
		top = top -> link ;
		size --;
		free(tmp);
	}
	printf("\nStack is Cleared!!!");
}