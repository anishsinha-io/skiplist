#include "slist/pstack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

PStackFrame *create_frame(SListNode *pointer) {
    PStackFrame *new_frame = malloc(sizeof(PStackFrame));
    new_frame->pointer = pointer;
    new_frame->next = NULL;
    return new_frame;
}

bool is_empty(const PStack *self) { return (self->total_capacity - self->frame_count) == 0; }

bool is_full(const PStack *self) {
    return self->frame_count == self->total_capacity;
}

void push(PStack *self, SListNode *pointer) {
    if (self->is_full(self)) {
        printf("stack_overflow");
        return;
    }
    PStackFrame *new_frame = self->create_frame(pointer);
    PStackFrame *p = self->top;
    new_frame->next = p;
    self->top = new_frame;
    self->frame_count++;
}

const SListNode *peek(const PStack *self) {
    return self->top->pointer;
}

SListNode *pop(PStack *self) {
    if (self->is_empty(self)) {
        printf("empty_stack");
        return NULL;
    }
    PStackFrame *t = self->top;
    self->top = t->next;
    SListNode *pointer = t->pointer;
    free(t);
    self->frame_count--;
    return pointer;
}

void clear(struct PStack *self) {

}

PStack *new_pstack() {
    PStack *new_pstack = malloc(sizeof(PStack));
    new_pstack->top = NULL;
    new_pstack->total_capacity = 50;
    new_pstack->frame_count = 0;
    new_pstack->is_empty = is_empty;
    new_pstack->is_full = is_full;
    new_pstack->create_frame = create_frame;
    new_pstack->push = push;
    new_pstack->pop = pop;
    new_pstack->peek = peek;
    return new_pstack;
}