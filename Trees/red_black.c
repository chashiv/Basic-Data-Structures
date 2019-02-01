/*
   Author : Shivam Chauhan
   Date   : Feb 1 , 2019
   Red Black (RB) Tree Implementation
*/
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

struct red_black
{
    enum { RED , BLACK } color;
    struct red_black *left_child ;
    int info ;
    struct red_black *right_child ;
    struct red_black *parent ;
}*root = NULL ;

int size = 0 ;
int is_empty();
void left_rotate( struct red_black *ptr );
void right_rotate( struct red_black *ptr );
void insert(int data );
void insert_balance( struct red_black *ptr );
void display_tree( struct red_black *ptr , int level );
int main()
{
	int choice , element ;
	while(1)
  	{
            //Resetting the color
            printf(ANSI_COLOR_RESET " " ANSI_COLOR_RESET);
            printf("\n\t\t---------------------------RB Search Tree---------------------------------") ;
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
            	             insert(element);
                           insert_balance(root);
            		           break;

                  case 2 : if (!is_empty())
                           {
                              printf("\nThe Tree is : \n");
                              display_tree( root , 1);
                           }
                           else
                           printf("\nTree is Empty!!!");
                           break;

	      /*          case 3 : if (!is_empty())
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


                  case 8 : if (!is_empty())
                           {
                              printf("\nEnter the element to be deleted :");
                              scanf("%d",&element); 
                              root = delete( root , element );
                           }
                           else
                              printf("\nTree is Empty!!!");  

          */                 break ;

        	     default : exit(0);
      			   break;

            }
      }
	return 0;
}
int is_empty()
{
    return root == NULL ;
}

void left_rotate( struct red_black *ptr)
{
    struct red_black *child_ptr = ptr -> right_child ;
    ptr -> right_child = child_ptr -> left_child ;
    if ( child_ptr -> left_child != NULL )
    {
        child_ptr -> left_child -> parent = ptr ;
    }
    child_ptr -> parent = ptr -> parent ;
    if ( ptr -> parent == NULL )
    {
        root = child_ptr ;
    }
    else if ( ptr == ptr -> parent -> left_child )
    {
        ptr -> parent -> left_child = child_ptr ;
    }
    else
    {
        ptr -> parent -> right_child = child_ptr ;
    }
    child_ptr -> left_child = ptr ;
    ptr -> parent = child_ptr ;
}

void right_rotate( struct red_black *ptr)
{
    struct red_black *child_ptr = ptr -> left_child ;
    ptr -> left_child = child_ptr -> right_child ;
    if ( child_ptr -> right_child != NULL )
    {
        child_ptr -> right_child -> parent = ptr ;
    }
    child_ptr -> parent = ptr -> parent ;
    if ( ptr -> parent == NULL )
    {
        root = child_ptr ;
    }
    else if ( ptr == ptr -> parent -> left_child )
    {
        ptr -> parent -> left_child = child_ptr ;
    }
    else
    {
        ptr -> parent -> right_child = child_ptr ;
    }
    child_ptr -> right_child = ptr ;
    ptr -> parent = child_ptr ;
}

void insert(int data)
{
    struct red_black *tmp, *ptr, *par;
    par = NULL;
    ptr = root;
    while( ptr != NULL )
    {
        par = ptr;
        if( data < ptr -> info )
        {
          ptr = ptr -> left_child ;
        }
        else if( data > ptr -> info )
        {
          ptr = ptr -> right_child;
        }
        else
        {
          printf("\nDuplicate key encountered!!!");
          return;
        }
    }
    tmp = (struct red_black *) malloc(sizeof(struct red_black));
    tmp->info = data;
    tmp->left_child = NULL;
    tmp->right_child = NULL;
    tmp->color = RED;
    tmp->parent = par;

    if(par==NULL)
    {
      root = tmp;
    }
    else if(tmp ->info < par->info )
    {
      par->left_child = tmp;
    }
    else
    {
      par->right_child = tmp;
    }
    insert_balance(tmp);
}


void insert_balance( struct red_black *ptr )
{
    struct red_black *uncle = NULL, *grandparent = NULL , *parent_pointer = NULL;
    // Parent is a Red Child
    while( ( ptr -> parent != NULL ) && (ptr -> parent -> color == RED ))
    {
        parent_pointer = ptr -> parent ;
        grandparent = parent_pointer -> parent ;
        // Parent is a left child
        if ( parent_pointer == grandparent -> left_child )
        {
          // uncle will be right child
            uncle = grandparent -> right_child ;
            /*
              Case 1 : Both parent and uncle are red
                     > color parent black
                     > color uncle black
                     > now x ( new node ) to be inserted points to grandparent
            */
            if ( uncle != NULL && uncle -> color == RED )
            {
                parent_pointer -> color = BLACK ;
                uncle -> color = BLACK ;
                grandparent -> color = RED ;
                ptr = grandparent ;
            }
            // Uncle is a black node
            else
            {
              /*
                Case 2 arises only if parent and node are opposite type of children

                Case 2.(i) : Parent is a left child , ptr is a right child || Parent is red , Uncle is black.
                       > left rotate on parent 
                       > ptr = parent
                       > parent = ptr -> parent
                > color parent black
                > color grandparent red
                > right rotate on grandparent

              */

                if ( ptr == parent_pointer -> right_child )
                {
                    left_rotate(parent_pointer);
                    ptr = parent_pointer ;
                    parent_pointer = ptr -> parent ;
                }

                parent_pointer -> color = BLACK ;
                grandparent -> color = RED ;
                right_rotate(grandparent);
            }
        }
        else
        {
          // if parent is a right child
           if ( parent_pointer == grandparent -> right_child )
            {
                // uncle will be left child
                uncle = grandparent -> left_child ;
                /*
                Case 1 : Both parent and uncle are red
                     > color parent black
                     > color uncle black
                     > now x ( new node ) to be inserted points to grandparent
                */
                if ( uncle != NULL && uncle -> color == RED )
                {
                    parent_pointer -> color = BLACK ;
                    uncle -> color = BLACK ;
                    grandparent -> color = RED ;
                    ptr = grandparent ;
                }
                // uncle is a black node
                else
                {
                  /*
                    Case 2 arises only if parent and node are opposite type of children

                    Case 2.(ii) : Parent is a right child , ptr is a left child || Parent is red , Uncle is black.
                           > right rotate on parent 
                           > ptr = parent
                           > parent = ptr -> parent
                    > color parent black
                    > color grandparent red
                    > left rotate on grandparent

                  */
                    if ( ptr == parent_pointer -> left_child )
                    {
                        right_rotate(parent_pointer);
                        ptr = parent_pointer ;
                        parent_pointer = ptr -> parent ;
                    }
                    parent_pointer -> color = BLACK ;
                    grandparent -> color = RED ;
                    left_rotate(grandparent);
                }

            }
        }
    }
    root -> color = BLACK ;
}

void display_tree( struct red_black *ptr , int level )
{
    int i ;
    if ( ptr == NULL )
    {
        return ;
    }
    else
    {
        display_tree( ptr -> right_child , level + 3 ) ;
        printf("\n") ;
        for ( i = 0 ; i < level ; i++ )
        {
            printf("  ");
        }
        if ( ptr -> color == RED )
            printf(ANSI_COLOR_RED "%d" ANSI_COLOR_RED, ptr -> info );
        else
            printf(ANSI_COLOR_CYAN "%d" ANSI_COLOR_CYAN , ptr -> info );
        display_tree( ptr -> left_child , level + 3 ) ;
    }
}
