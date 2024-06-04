/*
 * This file is a part of DS Project
 *
 * clist.h - circular linked list header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct CircularListElement_{
    void *data;
    struct CircularListElement_ *next;
} CircularListElement;

typedef struct CircularList_{
    int size;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    CircularListElement *head;
} CircularList;

void clist_init(CircularList *list, void (*destroy)(void *data));
void clist_destroy(CircularList *list);
int clist_ins_next(CircularList *list, CircularListElement *element, const void *data);
int clist_rem_next(CircularList *list, CircularListElement *element, void **data);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)

#endif
