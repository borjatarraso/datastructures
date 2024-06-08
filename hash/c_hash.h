/*
 * This file is a part of DS Project
 *
 * c_hash.h - chained hash table header
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

typedef struct ChainedHashTable_{
    int buckets;

    int (*h)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    int size;
    List *table;
} ChainedHashTable;

int chtbl_init(ChainedHashTable *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void (*
destroy)(void *data));
void chtbl_destroy(ChainedHashTable *htbl);
int chtbl_insert(ChainedHashTable *htbl, const void *data);
int chtbl_remove(ChainedHashTable *htbl, void **data);
int chtbl_lookup(const ChainedHashTable *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)

#endif
