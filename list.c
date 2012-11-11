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
void del_element_linked_list( pList *, int );

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
  pNode node;

  node = (pNode) malloc( sizeof(nodeType) );
  node->data = value;

  if( !*l || (*l)->data > value ){
    node->next = *l;
    *l = node;
  }

  else {
    index = *l;
    while( index->next  && index->next->data <= value)
      index = index->next;

    /* Do not allow duplicates */
    if( index->data == value ){
      free( node );
      return;
    }

    node->next = index->next;
    index->next = node;
  }
}

void del_element_linked_list( pList *l, int value )
{
  pNode node;
  pNode prev;

  node = *l;
  prev = NULL;

  while( node && node->data < value ){
    prev = node;
    node = node->next;
  }

  if( !node || node->data != value )
    return;
  else{
    if( !prev )
      *l = node->next;
    else
      prev->next = node->next;
  }

  free( node );
}

void remove_linked_list( pList *l )
{
  pNode node;

  node = *l;

  while( *l ){
    node = *l;
    *l = node->next;
    free( node );
  }
}

int
main( int argc, char *argv )
{
  /* Test case 1: is_linked_list_empty */
  pList l;
  l = NULL;
  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 2: add_element_linked_list */
  add_element_linked_list( &l, 1 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  add_element_linked_list( &l, 5 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  add_element_linked_list( &l, 3 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  add_element_linked_list( &l, 7 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 3: del_element_linked_list */
  del_element_linked_list( &l, 3 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  del_element_linked_list( &l, 7 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  del_element_linked_list( &l, 1 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 4: testing deleting non-existing */
  del_element_linked_list( &l, 2 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 5: testing adding duplicates */
  add_element_linked_list( &l, 3 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  add_element_linked_list( &l, 3 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 6: testing deleting all elements */
  del_element_linked_list( &l, 5 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  del_element_linked_list( &l, 3 );
  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 7: testing deleting empty list */
  del_element_linked_list( &l, 2 );
  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  /* Test case 8: testing remove the whole linked list */
  remove_linked_list( &l );
  assert( is_linked_list_empty( l ) );

  add_element_linked_list( &l, 5 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  add_element_linked_list( &l, 3 );
  assert( !is_linked_list_empty( l ) );
  display_linked_list( l );

  remove_linked_list( &l );
  assert( is_linked_list_empty( l ) );
  display_linked_list( l );

  return 0;
}
