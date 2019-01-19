/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Signle Linked List and its associated operations
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int info ;
  struct node *link ;
} *start = NULL ;

int size = 0 ;
int is_empty( struct node *start );
struct node *create_list(struct node * start ) ;
struct node *add_at_beg(struct node *start ) ;
struct node *add_at_end(struct node * start ) ;
struct node *add_at_position(struct node *) ;
struct node *add_after_node(struct node *) ;
struct node *add_before_node(struct node *) ;
void display(struct node *start ) ;
void count(struct node *) ;
struct node *del_from_beg(struct node *) ;
struct node *del_from_end(struct node *) ;
struct node *del_from_position(struct node *) ;
void print_reverse( struct node * );
struct node *reverse(struct node *) ;

int main()
{
  int choice ;
  while(1)
  {
      printf("\n\t\t----------------------------------------------------------------\n") ;
      printf("\n\t\t\t\t\tSingle Linked List \n\t\t\t\t----------------------------------") ;
      printf("\n\t\t\t\t1.  Create Single Linked List ") ;
      printf("\n\t\t\t\t2.  Add At Beginning ") ;
      printf("\n\t\t\t\t3.  Add At End ") ;
      printf("\n\t\t\t\t4.  Add At Position ") ;
      printf("\n\t\t\t\t5.  Add After Node ") ;
      printf("\n\t\t\t\t6.  Add Before Node ");
      printf("\n\t\t\t\t7.  Display ") ;
      printf("\n\t\t\t\t8.  Count ") ;
      printf("\n\t\t\t\t9.  Delete From Beginning  ") ;
      printf("\n\t\t\t\t10. Delete From End  ") ;
      printf("\n\t\t\t\t11. Delete From Position  ") ;
      printf("\n\t\t\t\t12. Print in Reverse ") ;
      printf("\n\t\t\t\t13. Reverse  ") ; 
      printf("\n\t\t\t\t14. Quit  ") ;
      printf("\n\t\t\t\t\nEnter your Choice : ") ;
      scanf("%d",&choice);

      switch ( choice )
      {
        case  1 : start = create_list( start ) ;
                  break ;

        case  2 : start = add_at_beg( start ) ;
                  break ;

        case  3 : start = add_at_end( start ) ;
                  break ;

        case  4 : start = add_at_position( start) ;
                  break ;

        case  5 : start = add_after_node( start) ;
                  break ;

        case  6 : start = add_before_node( start) ;
                  break ;

        case  7 : display( start) ;
                  break ;

        case  8 : count( start) ;
                  break ;

        case  9 : start = del_from_beg( start ) ;
                  break ;

        case 10 : start = del_from_end( start ) ;
                  break ;

        case 11 : start = del_from_position( start ) ;
                  break ;

        case 12 : print_reverse( start ) ;
                  break ;

        case 13 : start = reverse( start ) ;
                          break ;
        default : exit(0);
                  break ;

    }

  }
  return 0 ;
}

int is_empty( struct node *start )
{
  return ( start == NULL );
}

struct node *create_list(struct node *start)
{
  int n , i , element ;
  printf("\nEnter the number of elements :");
  scanf("%d",&n);
  for ( i = 1 ; i <= n ; i++ )
  {
    start = add_at_end(start );
  }
  if (n >= 1 )
    printf("\nSingle Linked List Created Successfully ");
  return start ;
}

struct node *add_at_beg(struct node *start )
{
  int element ;
  struct node * tmp ;
  printf("\nEnter the element to be inserted :");
  scanf("%d",&element);
  tmp = ( struct node *)malloc(sizeof(struct node)) ;
  tmp -> info = element ;
  tmp -> link = start ;
  start = tmp ;
  printf("\nElement %d Inserted ",element);
  size++;
  return start ;
}

struct node *add_at_end(struct node *start)
{
  int element ;
  struct node * tmp , * p = start ;
  tmp = ( struct node *)malloc(sizeof(struct node)) ;
  printf("\nEnter the element to be inserted :");
  scanf("%d",&element);
  tmp -> info = element ;
  tmp -> link = NULL ;
  if ( p == NULL)
  {
    start = tmp ;
  }
  else
  {
    while (p->link!=NULL)
    {
      p = p -> link ;
    }   
    p -> link = tmp ;
  }
  printf("\nElement %d Inserted ",element);
  size++;
  return start ;
}

struct node *add_at_position(struct node *start)
{
  int element , position , i;
  struct node * tmp , * p = start ;
  printf("\nEnter the position at which element is to be inserted :");
  scanf("%d",&position);  
  if (position == 1)
  {
    start = add_at_beg(start) ;
    return start ;
  }
  printf("\nEnter the element to be inserted :");
  scanf("%d",&element);
  tmp = ( struct node *)malloc(sizeof(struct node)) ;
  tmp -> info = element ;
  for ( i = 1 ; i < position - 1 && p != NULL ; i++ )
  {
    p = p -> link ;
  }
  if ( p == NULL)
  {
    printf("\nThere are less number of elements present ");
  }
  else
  {
    tmp -> link = p -> link ;
    p -> link = tmp ;
    size++;
  }
  return start ;
}

struct node *add_after_node(struct node *start)
{
  int element , node ;
  struct node * tmp , * p = start ;
  printf("\nEnter the node after which element is to be inserted :");
  scanf("%d",&node);  

  for ( p = start ; p != NULL ; p = p -> link)
  {
    if ( p -> info == node)
    {
      printf("\nEnter the element to be inserted :");
      scanf("%d",&element);
      tmp = (struct node *)malloc(sizeof(struct node )) ;
      tmp -> info = element ;
      tmp -> link = p -> link ;
      p -> link = tmp ;
      size++;
      return start ;
    }
  }
  printf("\n%d is not present in the list !!!", node);
  return start ;
}

struct node *add_before_node(struct node *start)
{
  int element , node ;
  struct node * tmp , * p = start ;
  if ( is_empty(start))
  {
    printf("\nThe List is empty!!!");
    return start ;
  }
  else
  {
    printf("\nEnter the node before which element is to be inserted :");
    scanf("%d",&node);  
    if ( p -> info == node )
    {
      start = add_at_beg(start) ;
      return start ;
    }
    for ( p = start ; p ->link != NULL ; p = p -> link)
    {
      if ( p -> link -> info == node)
      {
        printf("\nEnter the element to be inserted :");
        scanf("%d",&element);
        tmp = (struct node *)malloc(sizeof(struct node )) ;
        tmp -> info = element ;
        tmp -> link = p -> link ;
        p -> link = tmp ;
        size++;
        return start ;
      }
  }
  printf("\n%d is not present in the list !", node);
  return start ;  
  }
}

void display(struct node *start )
{
  struct node *p = start ;
  if ( is_empty(start) )
  {
    printf("\nList is Empty!!!");
  }
  
  else 
  {
    while(p!=NULL)
    {
      printf("%d ", p -> info );
      p = p -> link ;
    }
  }
    printf("\n");
}

void count(struct node *start )
{
  printf("\nTotal Number of elements are : %d" , size) ;
}

struct node *del_from_beg(struct node *start)
{
  struct node *tmp = start ;
  if (is_empty(start))
  {
    printf("\nList is Empty!!!");
    return start ;
  }
  else
  {
    start = start -> link ;
    printf("\nValue deleted %d" , tmp -> info);
    free(tmp);
    size--;
  }
  return start ;
}

struct node *del_from_end(struct node *start)
{
  struct node *tmp = start , *prev = tmp ;
  if ( is_empty(start ))
  {
    printf("\nList is Empty!!!");
    return start ;
  }
  while( tmp -> link != NULL )
  {
    prev = tmp ;
    tmp = tmp -> link ;
  }
  if ( size == 1 )
  {
    start = NULL ;
  }
  prev -> link = NULL;
  printf("\nValue deleted %d" , tmp -> info);
  free(tmp) ;
  size--;
  return start ;
}

struct node *del_from_position(struct node *start)
{
    int element , position , i;
    struct node * p = start , *tmp = NULL;
    printf("\nEnter the position at which element is to be deleted :");
    scanf("%d",&position);  
    if ( is_empty( start ) )
    {
      printf("\nList is Empty!!!");
      return start ;
    }

    if (position == 1)
    {
      start = del_from_beg(start) ;
      return start ;
    }

    for ( i = 1 ; i < position - 1 && p != NULL ; i++ )
    {
      p = p -> link ;
    }

    if( p == NULL)
    {
      printf("\nThere are less number of elements present ");
    }
    
    else
    {
      tmp = p -> link ;
      p -> link = tmp -> link ;
      printf("\nValue deleted %d" , tmp -> info);
      free(tmp);
      size--;
    }

    return start ;
}

void print_reverse(struct node * start )
{
  if ( start == NULL )
  {
    return ;
  }
  print_reverse( start -> link );
  printf("%d ",start -> info );
}


// struct node *reverse(struct node *start)
// {
//     struct node * current = start , * prev = NULL , * next = NULL ;
//     if ( start == NULL )
//     {
//       printf("\nList is Empty !!! ");
//       return ;

//     }
//     while( current != NULL )
//     {
//       next = current -> link ;
//       current -> link = prev ;
//       prev = current ;
//       current = next ;
//     }  
//     start = prev ;
//     printf("\nList Reversed Successfully ");
//     return start ;
// }

struct node *reverse(struct node *start)
{
    if ( start == NULL || start -> link == NULL)
    {
      return start ;
    }
    
    struct node * remaining = reverse( start -> link) ;
    start -> link -> link = start ;
    start -> link = NULL ;

    return remaining ;
}