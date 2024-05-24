/*
 * This file is a part of DS Project
 *
 * list.c - simple linked list implementation
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#include <stdlib.h>
#include "list.h"

int is_linked_list_empty(p_list l)
{
    return (l == NULL);
}

void add_element_linked_list(p_list *l, int value)
{
    p_node index;
    p_node node;

    node = (p_node) malloc(sizeof(node_t));
    node->data = value;

    if (!*l || (*l)->data > value) {
        node->next = *l;
        *l = node;
    }

    else {
        index = *l;
        while (index->next && index->next->data <= value)
            index = index->next;

        /* Do not allow duplicates */
        if (index->data == value) {
            free(node);
            return;
        }

        node->next = index->next;
        index->next = node;
    }
}

void del_element_linked_list(p_list *l, int value)
{
    p_node node;
    p_node prev;

    node = *l;
    prev = NULL;

    while (node && node->data < value) {
        prev = node;
        node = node->next;
    }

    if (!node || node->data != value)
        return;
    else {
        if (!prev)
            *l = node->next;
        else
            prev->next = node->next;
    }

    free(node);
}

void remove_linked_list(p_list *l)
{
    p_node node;

    node = *l;

    while(*l){
        node = *l;
        *l = node->next;
        free(node);
    }
}
