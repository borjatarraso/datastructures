/*
 * This file is a part of DS Project
 *
 * queue.h - queue header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destro list_destroy

int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head-data)
#define queue_size list_size

#endif
