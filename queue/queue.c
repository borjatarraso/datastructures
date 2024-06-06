/*
 * This file is a part of DS Project
 *
 * queue.c - queue implementation
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#include <stdlib.h>

#include "list.h"
#include "queue.h"

int queue_enqueue(Queue *queue, const void *data){
    return list_ins_next(queue, list_tail(queue), data);
}

int queue_dequeue(Queue *queue, void **data){
    return list_rem_next(queue, NULL, data);
}
