/*
 * This file is a part of DS Project
 *
 * clist.c - circular linked list implementation
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#include <stdlib.h>
#include <string.h>

#include "clist.h"

void clist_init(CircularList *list, void (*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

void clist_destroy(CircularList *list){
    void *data;

    while(clist_size(list) > 0){
        if(clist_rem_next(list, list->head, (void **)&data) == 0 && list->destroy != NULL){
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(CircularList));
}

int clist_ins_next(CircularList *list, CircularListElement *element, const void *data){
    CircularListElement *new_element;

    if((new_element = (CircularListElement *)malloc(sizeof(CircularListElement))) == NULL)
        return -1;

    new_element->data = (void *)data;

    if(clist_size(list) == 0){
        new_element->next = new_element;
        list->head = new_element;
    }else{
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;
    return 0;
}

int clist_rem_next(CircularList *list, CircularListElement *element, void **data){
    CircularListElement *old_element;

    if(clist_size(list) == 0)
        return -1;

    *data = element->next->data;

    if(element->next == element){
        old_element = element->next;
        list->head = NULL;
    }else{
        old_element = element->next;
        element->next = element->next->next;
        if(old_element == clist_head(list))
            list->head = old_element->next;
    }

    free(old_element);
    list->size--;
    return 0;
}
