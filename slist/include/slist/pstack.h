#include "models.h"
#include <stdbool.h>

#ifndef SKIPLIST_PSTACK_H
#define SKIPLIST_PSTACK_H

bool is_empty(const PStack *);
bool is_full(const PStack *);
void push(PStack *, SListNode *);
void clear(PStack *);
SListNode *pop(PStack *);
const SListNode *peek(const PStack *);
PStack *new_pstack(void);
PStackFrame *create_frame(SListNode *);

#endif //SKIPLIST_PSTACK_H
