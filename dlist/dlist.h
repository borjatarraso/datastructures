/*
 * This file is a part of DS Project
 *
 * dlist.h - doubly linked list header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

typedef struct DoubleListElement_ {
    void *data;
    struct DoubleListElement_ *prev;
    struct DoubleListElement_ *next;
} DoubleListElement;

typedef struct DoubleList_ {
    int size;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    DoubleListElement *head;
    DoubleListElement *tail;
} DoubleList;

void dlist_init(DoubleList *list, void (*destroy)(void *data));
void dlist_destroy(DoubleList *list);
int dlist_ins_next(DoubleList *list, DoubleListElement *element, const void *data);
int dlist_ins_prev(DoubleList *list, DoubleListElement *element, const void *data);
int dlist_remove(DoubleList *list, DoubleListElement *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif
