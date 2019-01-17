/*
   Author : Shivam Chauhan
   Date   : Jan 17 , 2019
   Binary Search Tree Recursive Implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct binary_search_tree
{
   struct binary_search_tree *left_child ;
	int info ;
	struct binary_search_tree *right_child ;
} *root = NULL ;


int size = 0 ;

int is_empty();
struct binary_search_tree *insert( struct binary_search_tree *ptr , int data ) ;
void preorder_display( struct binary_search_tree *root );
void inorder_display( struct binary_search_tree *root );
void postorder_display( struct binary_search_tree *root );
int search( struct binary_search_tree * root , int data );
int max( struct binary_search_tree * root );
int min( struct binary_search_tree * root );
struct binary_search_tree *delete( struct binary_search_tree *ptr , int data );

int main()
{
	int choice , element ;
	while(1)
  	{
            printf("\n\t\t---------------------------Binary Search Tree---------------------------------") ;
            if (!is_empty())
                  printf("\n\t\tRoot : %d" , root -> info );
            printf("\n\t\t\t\t 1.  Insert ") ;
            printf("\n\t\t\t\t 2.  Preorder ") ;
            printf("\n\t\t\t\t 3.  Inorder ") ;
            printf("\n\t\t\t\t 4.  Postorder ") ;
            printf("\n\t\t\t\t 5.  Count ") ; 
            printf("\n\t\t\t\t 6.  Search ") ; 
            printf("\n\t\t\t\t 7.  Height ") ;  
            printf("\n\t\t\t\t 8.  Maximum") ;
            printf("\n\t\t\t\t 9.  Minimum") ;         
            printf("\n\t\t\t\t10.  Delete") ;                   
            printf("\n\t\t\t\t11.  Exit ");
            printf("\n\t\t\t\t\nEnter your Choice : ") ;
            scanf("%d",&choice);	
            switch(choice)
            {
                  case 1 : printf("\nEnter the element :");
               			   scanf("%d",&element); 
               			   root = insert( root , element );
               			   break;

	              case 2 : if (!is_empty())
      			            {
      			                 printf("\nThe Preorder is : \n");
		                          preorder_display(root);
                           }
                           else
      				              printf("\nTree is Empty!!!");
      			
      			            break;

                  case 3 : if (!is_empty())
                           {
                              printf("\nThe Inorder is : \n");
                              inorder_display(root);
                           }
                           else
                              printf("\nTree is Empty!!!");
                        
                           break;

                  case 4 : if (!is_empty())
                           {
                              printf("\nThe Postorder is : \n");
                              postorder_display(root);
                           }
                           else
                              printf("\nTree is Empty!!!");
                        
                           break;

                  case 5 : printf("\nThe Number of Nodes are : %d",size);
                           break ;
                              
                  case 6 : if (!is_empty())
                           {
                              printf("\nEnter the data to be searched :");
                              scanf("%d",&element); 
                              if( search( root , element ))
                              {
                                    printf("\n%d is present in the tree!!!",element);
                              }
                              else
                              {
                                    printf("\n%d is not present in the tree!!!",element);
                              }
                           }
                           else
                              printf("\nTree is Empty!!!");
                        
                           break;
      	     
                  case 7 : printf("\nThe Height of the BST is : %.0f",ceil( log10( size + 1) / log10(2) ) );
                           break ;

                  case 8 : if (!is_empty())
                           {
                              printf("\nMaximum Node : %d ", max(root) );
                           }
                           else
                              printf("\nTree is Empty!!!");                  
                           break ;

                  case 9 : if (!is_empty())
                           {
                              printf("\nMinimum Node : %d ", min(root) );
                           }
                           else
                              printf("\nTree is Empty!!!");                  
                           break ;

                  case 10 : if (!is_empty())
                           {
                              printf("\nEnter the element to be deleted :");
                              scanf("%d",&element); 
                              root = delete( root , element );
                           }
                           else
                              printf("\nTree is Empty!!!");  

                           break ;

      	     default : exit(0);
      			   break;

            }
      }
	return 0;
}
int is_empty()
{
      return ( root == NULL ) ; 
}

struct binary_search_tree * insert( struct binary_search_tree *ptr , int data )
{
      if ( ptr == NULL )
      {
         ptr = ( struct binary_search_tree *) malloc ( sizeof( struct binary_search_tree )) ;
         ptr -> info = data ;
         ptr -> left_child = ptr -> right_child = NULL ;
         size++;
      }
      else if ( data < ptr -> info )
      {
         ptr -> left_child = insert( ptr -> left_child , data );
      }
      else if ( data > ptr -> info )
      {
        ptr -> right_child = insert( ptr -> right_child , data );
      }
      else
      {
         printf("\nDuplicate key encountered!!!");
      }
      return ptr;
}
void preorder_display( struct binary_search_tree *root )
{
      if ( root == NULL )
      {
            return;
      }
      printf("%d ", root -> info );
      preorder_display( root -> left_child );
      preorder_display( root -> right_child );
}
void inorder_display( struct binary_search_tree *root )
{
      if ( root == NULL )
      {
            return;
      }
      inorder_display( root -> left_child );
      printf("%d ", root -> info );
      inorder_display( root -> right_child );
}
void postorder_display( struct binary_search_tree *root )
{
      if ( root == NULL )
      {
            return;
      }
      postorder_display( root -> left_child );
      postorder_display( root -> right_child );
      printf("%d ", root -> info );
}
int search( struct binary_search_tree * root , int data )
{
      if( root == NULL )
      {
            return 0 ;
      }
      else if ( data < root -> info )
            search( root -> left_child , data );
      else if ( data > root -> info )
            search( root -> right_child , data );
      else
            return 1;
}
int max( struct binary_search_tree * root )
{
      if ( root == NULL )
      {
            return NULL;
      }

      else if ( root -> right_child == NULL ) 
      {
            return root -> info ;
      }
      else
      {
            return max( root -> right_child );
      }
}
int min( struct binary_search_tree * root )
{
      if ( root == NULL )
      {
            return NULL;
      }

      else if ( root -> left_child == NULL ) 
      {
            return root -> info ;
      }
      else
      {
            return min( root -> left_child );
      }
}
struct binary_search_tree * delete( struct binary_search_tree * ptr , int data )
{
   struct binary_search_tree * successor , *tmp ;
      if ( ptr == NULL )
      {
         printf("\n%d is not present in the tree!!!");
         return ptr ;
      }
      else if ( data < ptr -> info )
      {
         ptr -> left_child = delete( ptr -> left_child , data );
      }
      else if ( data > ptr -> info )
      {
        ptr -> right_child = delete( ptr -> right_child , data );
      }
      else
      {
         // Case C -> Two Child
         if ( ptr -> left_child != NULL && ptr -> right_child != NULL )
         {
            successor = ptr -> right_child ;
            while ( successor -> left_child )
            {
               successor = successor -> left_child ;
            }
            ptr -> info = successor -> info ;
            ptr -> right_child = delete( ptr -> right_child , successor -> info ) ;
         }
         else
         {
            tmp = ptr ;
            // Case B -> One Child
            if ( ptr -> left_child != NULL )
            {
               ptr = ptr -> left_child ;
            }
            else if ( ptr -> right_child != NULL )
            {
               ptr = ptr -> right_child ;
            }
            //  Case A -> No Child
            else
            {
               ptr = NULL ;
            }
            free(tmp);
            size--;
         }

      }
      return ptr;
} 

