/*
 * This file is a part of DS Project
 *
 * ut_list - simple linked list unit tests
 * Copyright (C) 2024  Borja Tarraso <borja.tarraso@member.fsf.org>
 */

#include <assert.h>
#include <stddef.h>
#include "list.h"

int main(void)
{
    p_list l;

    /* Test case 1: is_linked_list_empty */
    l = NULL;
    assert(is_linked_list_empty(l));

    /* Test case 2: add_element_linked_list */
    add_element_linked_list(&l, 1);
    assert(!is_linked_list_empty(l));

    add_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));

    add_element_linked_list(&l, 7);
    assert(!is_linked_list_empty(l));

    /* Test case 3: del_element_linked_list */
    del_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));

    del_element_linked_list(&l, 7);
    assert(!is_linked_list_empty(l));

    del_element_linked_list(&l, 1);
    assert(!is_linked_list_empty(l));

    /* Test case 4: testing deleting non-existing */
    del_element_linked_list(&l, 2);
    assert(!is_linked_list_empty(l));

    /* Test case 5: testing adding duplicates */
    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));

    /* Test case 6: testing deleting all elements */
    del_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));

    del_element_linked_list(&l, 3);
    assert(is_linked_list_empty(l));

    /* Test case 7: testing deleting empty list */
    del_element_linked_list(&l, 2);
    assert(is_linked_list_empty(l));

    /* Test case 8: testing remove the whole linked list */
    remove_linked_list(&l);
    assert(is_linked_list_empty(l));

    add_element_linked_list(&l, 5);
    assert(!is_linked_list_empty(l));

    add_element_linked_list(&l, 3);
    assert(!is_linked_list_empty(l));

    remove_linked_list(&l);
    assert(is_linked_list_empty(l));

    return 0;
}
