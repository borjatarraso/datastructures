/*
 * This file is a part of DS Project
 *
 * stack.c - stack imeplementation
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#include <stdlib.h>

#include "list.h"
#include "stack.h"

int stack_push(Stack *stack, const void *data){
    return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data){
    return list_rem_next(stack, NULL, data);
}
