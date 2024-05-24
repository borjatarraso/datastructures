/*
 * This file is a part of DS Project
 *
 * list.h - simple linked list header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef LIB_H_LIST
#define LIB_H_LIST

typedef struct _node{
    int data;
    struct _node *next;
} node_t;

typedef node_t *p_node;
typedef node_t *p_list;

int is_linked_list_empty(p_list);
void add_element_linked_list(p_list *, int);
void del_element_linked_list(p_list *, int);
void remove_linked_list(p_list *);

#endif
