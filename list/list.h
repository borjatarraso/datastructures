/*
 * This file is a part of DS Project
 *
 * list.h - singly linked list header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.>

typedef struct ListElement_ {
    void *data;
    struct ListElement_ *next;
} ListElement;

typedef struct List_ {
    int size;

    int (*match*)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    ListElement *head;
    ListElement *tail;
} List;

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElement *element, const void *data);
int list_rem_next(List *list, ListElement *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
