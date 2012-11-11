#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node{
  int data;
  struct _node *next;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *pList;

int is_linked_list_empty( pList );
void display_linked_list( pList );
void add_element_linked_list( pList *, int );

int is_linked_list_empty( pList l )
{
  return ( l == NULL );
}

void display_linked_list( pList l )
{
  pNode node;

  node = l;

  if( !l )
    printf("Empty linked list\n");
  else{
    while( node ){
      printf("%d -> ", node->data);
      node = node->next;
    }
    printf("\n");
  }
}

void add_element_linked_list( pList *l, int value )
{
  pNode index;
  pNode new_node;

  new_node = (pNode) malloc( sizeof(nodeType) );
  new_node->data = value;

  if( !*l || (*l)->data > value ){
    new_node->next = *l;
    *l = new_node;
  }
  else {
    index = *l;
    while( index->next  && index->next->data <= value)
      index = index->next;

    new_node->next = index->next;
    index->next = new_node;
  }
}

int
main( int argc, char *argv )
{
  
  /* Test case: is_linked_list_empty */
  pList l;

  l = NULL;

  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case: add_element_linked_list */
  add_element_linked_list( &l, 1 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  return 0;
}
