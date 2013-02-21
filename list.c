/*
 * This file is a part of DS Project
 *
 * list.c - simple linked list implementation
 * Copyright (C) 2013  Borja Tarraso <borja.tarraso@member.fsf.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _node{
    int data;
    struct _node *next;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *pList;

int is_linked_list_empty(pList);
void display_linked_list(pList);
void add_element_linked_list(pList*, int);
void del_element_linked_list(pList *, int);
void remove_linked_list(pList *);

int is_linked_list_empty(pList l)
{
    return (l == NULL);
}

void display_linked_list(pList l)
{
    pNode node;

    node = l;

    if (!l)
        printf("Empty linked list\n");
    else {
        while (node) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

void add_element_linked_list(pList *l, int value)
{
    pNode index;
    pNode node;

    node = (pNode) malloc(sizeof(nodeType));
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

void del_element_linked_list(pList *l, int value)
{
    pNode node;
    pNode prev;

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

void remove_linked_list(pList *l)
{
    pNode node;

    node = *l;

    while(*l){
        node = *l;
        *l = node->next;
        free(node);
    }
}

int main(int argc, char *argv[])
{
    pList l;

    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(1);
    }

    /* Test case 1: is_linked_list_empty */
    l = NULL;
    assert(is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 2: add_element_linked_list */
    add_element_linked_list(&l, 1);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    add_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    add_element_linked_list(&l, 7);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 3: del_element_linked_list */
    del_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    del_element_linked_list(&l, 7);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    del_element_linked_list(&l, 1);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 4: testing deleting non-existing */
    del_element_linked_list(&l, 2);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 5: testing adding duplicates */
    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 6: testing deleting all elements */
    del_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    del_element_linked_list(&l, 3);
    assert(is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 7: testing deleting empty list */
    del_element_linked_list(&l, 2);
    assert(is_linked_list_empty(l));
    display_linked_list(l);

    /* Test case 8: testing remove the whole linked list */
    remove_linked_list(&l);
    assert(is_linked_list_empty(l));

    add_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));
    display_linked_list(l);

    remove_linked_list(&l);
    assert(is_linked_list_empty(l));
    display_linked_list(l);

    return 0;
}
