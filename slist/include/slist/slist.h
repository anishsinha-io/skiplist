#include "models.h"

#ifndef SKIPLIST_SLIST_H
#define SKIPLIST_SLIST_H

SList *new_slist(void);
void insert(SList *, double);
void print(const SList *);
void print_metadata(const SList *);
void destroy(SList *);
void delete(SList *, double);

void rebalance_levels(SList *);
void add_level(SList *);
void remove_level(SList *);

SListNode *create_sentinel(SIGN);
SListNode *create_node(double);
SListNode *search(const SList *, double);
PStack *get_left_adjacent_pointers(const SList *, double);

#endif //SKIPLIST_SLIST_H
