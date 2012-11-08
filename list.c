#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node{
  int data;
  struct _node *next;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *pList;

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

int
main( int argc, char *argv )
{
  
  /* Test case: is_linked_list_empty */
  pList l;

  l = NULL;

  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  return 0;
}
