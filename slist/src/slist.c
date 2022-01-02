#include "slist/slist.h"
#include "slist/models.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "slist/pstack.h"
#include "slist/slist-util.h"

void print(const SList *self) {

}

void print_metadata(const SList *self) {
    printf("\n----- START SKIP LIST METADATA -----\n\n");
    printf(">length: %d\n", self->length);
    printf(">max_levels: %d\n", self->max_levels);
    printf("\n----- END SKIP LIST METADATA -----\n");
}

void destroy(SList *self) {

}


void add_level(SList *self) {
    SListNode *new_top_left = self->create_sentinel(negative);
    SListNode *new_top_right = self->create_sentinel(positive);
    new_top_left->next = new_top_right;
    new_top_right->prev = new_top_left;
    new_top_left->bottom = self->top_left;
    new_top_right->bottom = self->top_right;
    self->top_left->top = new_top_left;
    self->top_right->top = new_top_right;
    self->top_left = new_top_left;
    self->top_right = new_top_right;
}

void remove_level(SList *self) {
    if (self->max_levels == 1) {
        printf("not_enough_levels");
        return;
    }
    SListNode *new_top_left = self->top_left->bottom;
    SListNode *new_top_right = self->top_right->bottom;
    SListNode *it = self->top_left;
    while (it != NULL) {
        if (it->next == NULL) {
            it = NULL;
            free(it);
        } else {
            it = it->next;
            it->prev = NULL;
            free(it->prev);
        }
    }
    self->top_left = new_top_left;
    self->top_right = new_top_right;
}

void rebalance_levels(SList *self) {
    unsigned int old_max_levels = self->max_levels;
    unsigned int new_max_levels = self->util->recalculate_max_levels(self->length);
    if (old_max_levels == new_max_levels) return;
    self->max_levels = new_max_levels;
    if (old_max_levels < new_max_levels) {
        self->add_level(self);
        return;
    } else {
        self->remove_level(self);
        return;
    }
}

SListNode *create_sentinel(SIGN sign) {
    SListNode *new_sentinel = malloc(sizeof(SListNode));
    switch (sign) {
        case positive:
            new_sentinel->val = INFINITY;
            break;
        case negative:
            new_sentinel->val = -INFINITY;
            break;
        default:
            printf("unknown_symbol");
            exit(1);
    }
    new_sentinel->bottom = new_sentinel->top = new_sentinel->prev = new_sentinel->next = NULL;
    new_sentinel->is_sentinel = true;
    return new_sentinel;
}

SListNode *create_node(double val) {
    SListNode *new_node = malloc(sizeof(SListNode));
    new_node->val = val;
    new_node->bottom = new_node->top = new_node->prev = new_node->next = NULL;
    return new_node;
}

/// search will search the passed-in (by pointer) SList* (self) for the passed-in double (val)
/// @param self
/// @param val
/// @return SListNode* -> pointer to the found node or a null pointer

SListNode *search(const SList *self, double val) {
    SListNode *it = self->top_left;
    for (unsigned int i = 0; i < self->max_levels; i++) {
        while (it->next != NULL && it->next->val < val) {
            it = it->next;
        }
        if (it->bottom != NULL) {
            it = it->bottom;
        }
    }
    if (it->next->val != val) {
        return NULL;
    }
    return it->next;
}

PStack *get_left_adjacent_pointers(const SList *self, double val) {
    PStack *pointer_stack = new_pstack();
    SListNode *it = self->top_left;
    for (unsigned int i = 0; i < self->max_levels; i++) {
        while (it->next->val < val) {
            it = it->next;
        }
        if (it->bottom == NULL) {
            pointer_stack->push(pointer_stack, it);
            break;
        }
        pointer_stack->push(pointer_stack, it);
        it = it->bottom;
    }
    return pointer_stack;
}

void insert(SList *self, double val) {
    if (self->length == 0) {
        SListNode *new_node = self->create_node(val);
        self->bottom_left->next = new_node;
        new_node->prev = self->bottom_left;
        self->bottom_right->prev = new_node;
        new_node->next = self->bottom_right;
    } else {
        PStack *pointer_stack = get_left_adjacent_pointers(self, val);
        unsigned int random_height = self->util->random_height(self->max_levels);
        printf("%d\n", random_height);
        SListNode *t = NULL;
        for (unsigned int i = 0; i < random_height; i++) {
            SListNode *new_stacked_node = self->create_node(val);
            SListNode *p = pointer_stack->pop(pointer_stack);
            SListNode *n = p->next;
            p->next = new_stacked_node;
            new_stacked_node->prev = p;
            n->prev = new_stacked_node;
            new_stacked_node->next = n;
            if (t == NULL) {
                t = new_stacked_node;
            } else {
                new_stacked_node->bottom = t;
                t->top = new_stacked_node;
                t = new_stacked_node;
            }
        }
    }
    self->length++;
    if (self->length > 2) {
        self->rebalance_levels(self);
    }
}

void delete(SList *self, double val) {
    SListNode *root_node = self->search(self, val);
    if (root_node == NULL) {
        printf("%f not in list!", val);
        return;
    }
    while (root_node != NULL) {
        SListNode *p = root_node->prev;
        SListNode *n = root_node->next;
        p->next = n;
        n->prev = p;
        SListNode *t = root_node;
        root_node = root_node->top;
        free(t);
    }
    self->length--;
    self->rebalance_levels(self);
}

SList *new_slist() {
    SList *new_slist = malloc(sizeof(SList));
    new_slist->util = new_slist_util();

    new_slist->print = print;
    new_slist->print_metadata = print_metadata;
    new_slist->create_sentinel = create_sentinel;
    new_slist->create_node = create_node;
    new_slist->delete = delete;
    new_slist->add_level = add_level;
    new_slist->remove_level = remove_level;
    new_slist->rebalance_levels = rebalance_levels;
    new_slist->destroy = destroy;
    new_slist->insert = insert;
    new_slist->search = search;
    new_slist->get_left_adjacent_pointers = get_left_adjacent_pointers;

    new_slist->length = 0;
    new_slist->max_levels = 1;
    new_slist->current_height = 0;

    new_slist->bottom_left = new_slist->create_sentinel(negative);
    new_slist->bottom_right = new_slist->create_sentinel(positive);

    new_slist->bottom_left->next = new_slist->bottom_right;
    new_slist->bottom_right->prev = new_slist->bottom_left;

    new_slist->top_left = new_slist->bottom_left;
    new_slist->top_right = new_slist->bottom_right;

    return new_slist;
}

