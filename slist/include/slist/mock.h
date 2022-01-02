#include "models.h"

#ifndef SKIPLIST_MOCK_H
#define SKIPLIST_MOCK_H

SList *create_mock();
PStack *traverse_mock(SList *, double);
SListNode *search_mock(SList *, double);
void insert_mock(SList *, double);
unsigned int random_height_mock(unsigned int);
void print_mock(SList *);

#endif //SKIPLIST_MOCK_H
