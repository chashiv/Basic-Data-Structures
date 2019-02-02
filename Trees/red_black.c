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
void preorder_display( struct red_black *root );
void inorder_display( struct red_black *root );
void postorder_display( struct red_black *root );
int get_height( struct red_black *ptr );
struct red_black *search( int data );
void delete( int data );
void delete_balance( struct red_black *ptr );
struct red_black *get_successor( struct red_black *ptr);
struct red_black *leaf ;
int main()
{
	int choice , element ;
  leaf = ( struct red_black *)malloc(sizeof(struct red_black));
  leaf -> info = -1;
  leaf -> color = BLACK ;
  leaf -> parent = leaf -> left_child = leaf -> right_child = NULL;
  root = leaf ;
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
            printf("\n\t\t\t\t 8.  Search ") ;                    
            printf("\n\t\t\t\t 9.  Delete") ;                   
            printf("\n\t\t\t\t10.  Exit ");
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


                  case 8 : if (!is_empty())
                           {
                              printf("\nEnter the element to be searched :");
                              scanf("%d",&element); 
                              if ( search(element )!= leaf )
                                  printf("\n%d is present in the tree.",element);
                              else
                                  printf("\n%d is not present in the tree.",element);
                           }
                           else
                              printf("\nTree is Empty!!!");  

                           break ;
                  case 9 : if (!is_empty())
                           {
                              printf("\nEnter the element to be deleted :");
                              scanf("%d",&element); 
                              delete(element);
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
    return root == leaf ;
}

void left_rotate( struct red_black *ptr)
{
    struct red_black *child_ptr = ptr -> right_child ;
    ptr -> right_child = child_ptr -> left_child ;
    if ( child_ptr -> left_child != leaf )
    {
        child_ptr -> left_child -> parent = ptr ;
    }
    child_ptr -> parent = ptr -> parent ;
    if ( ptr -> parent == leaf )
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
    if ( child_ptr -> right_child != leaf )
    {
        child_ptr -> right_child -> parent = ptr ;
    }
    child_ptr -> parent = ptr -> parent ;
    if ( ptr -> parent == leaf )
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
    par = leaf;
    ptr = root;
    while( ptr != leaf )
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
    tmp -> info = data;
    tmp -> left_child = leaf;
    tmp -> right_child = leaf;
    tmp -> color = RED;
    tmp -> parent = par;
    size++;

    if( par == leaf )
    {
      root = tmp;
    }
    else if( tmp -> info < par -> info )
    {
      par -> left_child = tmp;
    }
    else
    {
      par -> right_child = tmp;
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
    if ( ptr == leaf )
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
void preorder_display( struct red_black *root )
{
      if ( root == leaf )
      {
            return;
      }
      printf("%d ", root -> info );
      preorder_display( root -> left_child );
      preorder_display( root -> right_child );
}
void inorder_display( struct red_black *root )
{
      if ( root == leaf )
      {
            return;
      }
      inorder_display( root -> left_child );
      printf("%d ", root -> info );
      inorder_display( root -> right_child );
}
void postorder_display( struct red_black *root )
{
      if ( root == leaf )
      {
            return;
      }
      postorder_display( root -> left_child );
      postorder_display( root -> right_child );
      printf("%d ", root -> info );
}

int get_height( struct red_black *ptr)
{
   int left_height , right_height ;
   if ( ptr == leaf )
   {
      return 0;
   }
   left_height = get_height( ptr -> left_child );
   right_height = get_height( ptr -> right_child );
   return ( left_height > right_height ? left_height + 1 : right_height + 1);
}

struct red_black * search( int data)
{
    struct red_black *ptr = root ;
    while( ptr != leaf )
    {
        if ( data < ptr -> info )
        {
            ptr = ptr -> left_child;
        }
        else if ( data > ptr -> info )
        {
            ptr = ptr -> right_child;
        }
        else
        {
            break;
        }
    }
    return ptr ;
}
struct red_black *get_successor( struct red_black *ptr )
{
    ptr = ptr -> right_child ;
    while (ptr -> left_child != leaf )
    {
        ptr = ptr -> left_child ;
    }

    return ptr ;
}

void delete( int data )
{
    struct red_black *ptr = search(data) , *successor , *child_ptr = NULL ;
    if ( ptr != leaf )
    {
        if ( ptr -> left_child != leaf && ptr -> right_child != leaf )
        {
            successor = get_successor(ptr);
            ptr -> info = successor -> info ;
            ptr = successor ;
        }
        if ( ptr -> left_child != leaf )
        {
            child_ptr = ptr -> left_child ;
        }
        else
        {
            child_ptr = ptr -> right_child ;
        }
        child_ptr -> parent = ptr -> parent ;
        if ( ptr -> parent == leaf )
        {
            root = child_ptr;
        }
        else if ( ptr == ptr -> parent -> left_child )
        {
            ptr -> parent -> left_child = child_ptr ;
        }
        else
        {
            ptr -> parent -> right_child = child_ptr ;
        }
        if ( child_ptr == root )
        {
            child_ptr -> color = BLACK ;
        }
        else if ( ptr -> color == BLACK )
        {
            if ( child_ptr != leaf )
                child_ptr -> color = BLACK ;
            else
                delete_balance(child_ptr);
        }
    }
    else
    {
        printf("\n%d is not present in the tree!!!",data);
    }
}

void delete_balance(struct red_black *ptr)
{
  struct red_black *sib;

  while( ptr != root )
  {
    if( ptr != NULL && ptr == ptr-> parent-> left_child )
    {
            sib = ptr -> parent -> right_child;
            if( sib -> color == RED )
            {
                sib -> color = BLACK ;
                ptr -> parent -> color = RED;
                left_rotate( ptr -> parent);
                sib = ptr -> parent -> right_child; 
            }
            if(sib -> left_child -> color == BLACK && sib -> right_child -> color == BLACK )
            {
                sib -> color = RED ;
                if( ptr -> parent -> color == RED )
                {
                    ptr -> parent -> color = BLACK;
                    return;
                }
                else
                    ptr = ptr -> parent; 
            }
            else
            {
                if( sib -> right_child -> color == BLACK )  
                {
                    sib -> left_child -> color = BLACK;
                    sib -> color = RED;
                    right_rotate(sib);
                    sib = ptr -> parent -> right_child;
                }
                sib -> color = ptr -> parent -> color; 
                ptr -> parent -> color = BLACK;
                sib -> right_child -> color = BLACK;
                left_rotate( ptr -> parent);
                return;
            }
    }
    else
    {
            sib = ptr -> parent -> left_child;
            if( sib -> color == RED )
            {
                sib -> color = BLACK ;
                ptr -> parent -> color = RED;
                right_rotate( ptr -> parent);
                sib = ptr -> parent -> left_child; 
            }
            if(sib -> left_child -> color == BLACK && sib -> right_child -> color == BLACK )
            {
                sib -> color = RED ;
                if( ptr -> parent -> color == RED )
                {
                    ptr -> parent -> color = BLACK;
                    return;
                }
                else
                    ptr = ptr -> parent;  
            }
            else
            {
                if( sib -> left_child -> color == BLACK ) 
                {
                    sib -> right_child -> color = BLACK;
                    sib -> color = RED;
                    left_rotate(sib);
                    sib = ptr -> parent -> left_child;
                }
                sib -> color = ptr -> parent -> color;  
                ptr -> parent -> color = BLACK;
                sib -> left_child -> color = BLACK;
                right_rotate( ptr -> parent);
                return;
            }
    }
  }
}
