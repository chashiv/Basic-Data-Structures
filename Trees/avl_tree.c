/*
   Author : Shivam Chauhan
   Date   : Jan 25 , 2019
   Adelson Velskii Landis(AVL) Tree Implementation
*/
#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

struct avl
{
	struct avl *left_child ;
	int info ;
	struct avl *right_child ;
} *root = NULL ;


int size = 0 ;

int is_empty();
int get_height( struct avl *ptr ) ;
int get_balance( struct avl *ptr ) ;
struct avl *right_rotate( struct avl *ptr);
struct avl *left_rotate( struct avl *ptr);
struct avl *insert( struct avl *ptr , int data ) ;
void print_order( struct avl *ptr , int indent );
void preorder_display( struct avl *root );
void inorder_display( struct avl *root );
void postorder_display( struct avl *root );
// int search( struct avl *root , int data );
// struct avl *delete( struct avl *ptr , int data );

int main()
{
	int choice , element ;
	while(1)
  	{
            printf("\n\t\t---------------------------AVL Search Tree---------------------------------") ;
            if (!is_empty())
                  printf("\n\t\tRoot : %d" , root -> info );
            printf("\n\t\t\t\t 1.  Insert ") ;
            printf("\n\t\t\t\t 2.  Print Tree ") ;
            printf("\n\t\t\t\t 3.  Preorder ") ;
            printf("\n\t\t\t\t 4.  Inorder ") ;
            printf("\n\t\t\t\t 5.  Postorder ") ;
            printf("\n\t\t\t\t 6.  Count ") ; 
            printf("\n\t\t\t\t 7.  Height ") ;          
            printf("\n\t\t\t\t 8.  Delete") ;                   
            printf("\n\t\t\t\t 9.  Exit ");
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
                              printf("\nThe Tree is : \n");
                              print_order( root , 0);
                           }
                           else
                           printf("\nTree is Empty!!!");
                           break;

	                case 3 : if (!is_empty())
      			               {
      			                 printf("\nThe Preorder is : \n");
		                         preorder_display( root );
                           }
                           else
      			                 printf("\nTree is Empty!!!");
      			               break;

                  case 4 : if (!is_empty())
                           {
                             printf("\nThe Inorder is : \n");
                             inorder_display(root);
                           }
                           else
                              printf("\nTree is Empty!!!");
                        
                           break;

                  case 5 : if (!is_empty())
                           {
                              printf("\nThe Postorder is : \n");
                              postorder_display(root);
                           }
                           else
                              printf("\nTree is Empty!!!");
                        
                           break;

                  case 6 : printf("\nThe Number of Nodes are : %d",size);
                           break ;
                  case 7 : printf("\nThe Height of the BST is : %d",get_height(root));
                           break ;


                  // case 8 : if (!is_empty())
                  //          {
                  //             printf("\nEnter the element to be deleted :");
                  //             scanf("%d",&element); 
                  //             root = delete( root , element );
                  //          }
                  //          else
                  //             printf("\nTree is Empty!!!");  

                  //          break ;

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
int get_height( struct avl *ptr)
{
   int left_height , right_height ;
   if ( ptr == NULL )
   {
      return 0;
   }
   left_height = get_height( ptr -> left_child );
   right_height = get_height( ptr -> right_child );
   return ( left_height > right_height ? left_height + 1 : right_height + 1);
}
int get_balance ( struct avl *ptr)
{
   if ( ptr == NULL )
   {
      return 0 ;
   }
   return get_height(ptr -> left_child) - get_height(ptr-> right_child);
}
struct avl *right_rotate( struct avl *ptr)
{
   struct avl *child_ptr = ptr -> left_child ;
   ptr -> left_child = child_ptr -> right_child ;
   child_ptr -> right_child = ptr ;
   return child_ptr ;
}
struct avl *left_rotate( struct avl *ptr)
{
   struct avl *child_ptr = ptr -> right_child ;
   ptr -> right_child = child_ptr -> left_child ;
   child_ptr -> left_child = ptr ;
   return child_ptr ;
}
struct avl *insert( struct avl *ptr , int data )
{
      if ( ptr == NULL )
      {
         ptr = ( struct avl *) malloc ( sizeof( struct avl )) ;
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
       int balance = get_balance( ptr );
       // LL
       if ( balance > 1 && data < ptr -> left_child -> info) 
           return right_rotate(ptr); 
       // RR 
       if (balance < -1 && data > ptr -> right_child -> info) 
           return left_rotate(ptr); 
       // LR 
       if (balance > 1 && data > ptr -> left_child -> info) 
       { 
           ptr -> left_child =  left_rotate(ptr -> left_child); 
           return right_rotate(ptr); 
       } 
       // RL
       if (balance < -1 && data < ptr -> right_child ->info) 
       { 
           ptr -> right_child = right_rotate(ptr -> right_child); 
           return left_rotate(ptr); 
       } 
       return ptr;       
}
void preorder_display( struct avl *root )
{
      if ( root == NULL )
      {
            return;
      }
      printf("%d ", root -> info );
      preorder_display( root -> left_child );
      preorder_display( root -> right_child );
}
void inorder_display( struct avl *root )
{
      if ( root == NULL )
      {
            return;
      }
      inorder_display( root -> left_child );
      printf("%d ", root -> info );
      inorder_display( root -> right_child );
}
void postorder_display( struct avl *root )
{
      if ( root == NULL )
      {
            return;
      }
      postorder_display( root -> left_child );
      postorder_display( root -> right_child );
      printf("%d ", root -> info );
}
void print_order( struct avl *ptr, int space)
{
    int i;
    if ( ptr == NULL )
    { 
        return; 
    }
    space += COUNT;
    print_order ( ptr -> right_child , space);   
    printf("\n"); 
    for ( i = COUNT ; i < space ; i++ ) 
    {
        printf("%s"," "); 
    }
    printf("%d\n", ptr->info);   
    print_order(ptr->left_child, space); 
} 
