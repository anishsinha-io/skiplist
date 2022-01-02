#include "slist/mock.h"
#include "slist/models.h"
#include "slist/slist.h"
#include "slist/pstack.h"
#include "slist/util.h"
#include <stdlib.h>
#include <sodium.h>

// create_mock creates a testable mock of a skip list by hand, where the location of
// each node is known.
SList *create_mock() {
    SList *mock1 = new_slist();
//    first row
    SListNode *r1n1 = mock1->create_node(1);
    SListNode *r1n2 = mock1->create_node(2);
    SListNode *r1n3 = mock1->create_node(3);
    SListNode *r1n4 = mock1->create_node(4);
    SListNode *r1n5 = mock1->create_node(5);
    SListNode *r1n6 = mock1->create_node(6);
    SListNode *r1n7 = mock1->create_node(7);
    SListNode *r1n8 = mock1->create_node(8);
    SListNode *r1n9 = mock1->create_node(9);
    SListNode *r1n10 = mock1->create_node(10);
    SListNode *r1n11 = mock1->create_node(11);
    SListNode *r1n12 = mock1->create_node(12);
    SListNode *r1n13 = mock1->create_node(13);

    mock1->bottom_left->next = r1n1;
    r1n1->prev = mock1->bottom_left;
    r1n2->prev = r1n1;
    r1n1->next = r1n2;
    r1n3->prev = r1n2;
    r1n2->next = r1n3;
    r1n4->prev = r1n3;
    r1n3->next = r1n4;
    r1n5->prev = r1n4;
    r1n4->next = r1n5;
    r1n6->prev = r1n5;
    r1n5->next = r1n6;
    r1n7->prev = r1n6;
    r1n6->next = r1n7;
    r1n8->prev = r1n7;
    r1n7->next = r1n8;
    r1n9->prev = r1n8;
    r1n8->next = r1n9;
    r1n10->prev = r1n9;
    r1n9->next = r1n10;
    r1n11->prev = r1n10;
    r1n10->next = r1n11;
    r1n12->prev = r1n11;
    r1n11->next = r1n12;
    r1n13->prev = r1n12;
    r1n12->next = r1n13;
    r1n13->next = mock1->bottom_right;
    mock1->bottom_right->prev = r1n13;

//    Second row
    mock1->add_level(mock1);

    SListNode *r2n1 = mock1->create_node(2);
    SListNode *r2n2 = mock1->create_node(3);
    SListNode *r2n3 = mock1->create_node(4);
    SListNode *r2n4 = mock1->create_node(5);
    SListNode *r2n5 = mock1->create_node(6);
    SListNode *r2n6 = mock1->create_node(8);
    SListNode *r2n7 = mock1->create_node(9);
    SListNode *r2n8 = mock1->create_node(10);
    SListNode *r2n9 = mock1->create_node(12);
    SListNode *r2n10 = mock1->create_node(13);

    mock1->top_left->next = r2n1;
    r2n1->prev = mock1->top_left;
    r2n1->next = r2n2;
    r2n2->prev = r2n1;
    r2n2->next = r2n3;
    r2n3->prev = r2n2;
    r2n3->next = r2n4;
    r2n4->prev = r2n3;
    r2n4->next = r2n5;
    r2n5->prev = r2n4;
    r2n5->next = r2n6;
    r2n6->prev = r2n5;
    r2n6->next = r2n7;
    r2n7->prev = r2n6;
    r2n7->next = r2n8;
    r2n8->prev = r2n7;
    r2n8->next = r2n9;
    r2n9->prev = r2n8;
    r2n9->next = r2n10;
    r2n10->prev = r2n9;
    r2n10->next = mock1->top_right;
    mock1->top_right->prev = r2n10;

    r2n1->bottom = r1n2;
    r1n2->top = r2n1;
    r2n2->bottom = r1n3;
    r1n3->top = r2n2;
    r2n3->bottom = r1n4;
    r1n4->top = r2n3;
    r2n4->bottom = r1n5;
    r1n5->top = r2n4;
    r2n5->bottom = r1n6;
    r1n6->top = r2n5;
    r2n6->bottom = r1n8;
    r1n8->top = r2n6;
    r2n7->bottom = r1n9;
    r1n9->top = r2n7;
    r2n8->bottom = r1n10;
    r1n10->top = r2n8;
    r2n9->bottom = r1n12;
    r1n12->top = r2n9;
    r2n10->bottom = r1n13;
    r1n13->top = r2n10;

//    Third row

    mock1->add_level(mock1);

    SListNode *r3n1 = mock1->create_node(2);
    SListNode *r3n2 = mock1->create_node(3);
    SListNode *r3n3 = mock1->create_node(4);
    SListNode *r3n4 = mock1->create_node(5);
    SListNode *r3n5 = mock1->create_node(8);
    SListNode *r3n6 = mock1->create_node(10);
    SListNode *r3n7 = mock1->create_node(12);

    mock1->top_left->next = r3n1;
    r3n1->prev = mock1->top_left;
    r3n1->next = r3n2;
    r3n2->prev = r3n1;
    r3n2->next = r3n3;
    r3n3->prev = r3n2;
    r3n3->next = r3n4;
    r3n4->prev = r3n3;
    r3n4->next = r3n5;
    r3n5->prev = r3n4;
    r3n5->next = r3n6;
    r3n6->prev = r3n5;
    r3n6->next = r3n7;
    r3n7->prev = r3n6;
    r3n7->next = mock1->top_right;
    mock1->top_right->prev = r3n7;

    r3n1->bottom = r2n1;
    r2n1->top = r3n1;
    r3n2->bottom = r2n2;
    r2n2->top = r3n2;
    r3n3->bottom = r2n3;
    r2n3->top = r3n3;
    r3n4->bottom = r2n4;
    r2n4->top = r3n4;
    r3n5->bottom = r2n6;
    r2n6->top = r3n5;
    r3n6->bottom = r2n8;
    r2n8->top = r3n6;
    r3n7->bottom = r2n9;
    r2n9->top = r3n7;

//    Fourth row

    mock1->add_level(mock1);

    SListNode *r4n1 = mock1->create_node(4);
    SListNode *r4n2 = mock1->create_node(5);
    SListNode *r4n3 = mock1->create_node(10);

    mock1->top_left->next = r4n1;
    r4n1->prev = mock1->top_left;
    r4n1->next = r4n2;
    r4n2->prev = r4n1;
    r4n2->next = r4n3;
    r4n3->prev = r4n2;
    r4n3->next = mock1->top_right;
    mock1->top_right->prev = r4n3;

    r4n1->bottom = r3n3;
    r3n3->top = r4n1;
    r4n2->bottom = r3n4;
    r3n4->top = r4n2;
    r4n3->bottom = r3n6;
    r3n6->top = r4n3;

    mock1->length = 13;
    mock1->max_levels = 4;
    mock1->current_height = 4;

    return mock1;
}

PStack *traverse_mock(SList *self, double val) {
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

SListNode *search_mock(SList *self, double val) {
    SListNode *it = self->top_left;
    for (unsigned int i = 0; i < self->max_levels; i++) {
        while (it->next->val < val) {
            it = it->next;
        }
        if (it->bottom == NULL) break;
        it = it->bottom;
    }
    if (it->next->val == val) return it->next;
    return NULL;
}

unsigned int random_height_mock(unsigned int max_levels) {
    if (sodium_init() < 0) {
        printf("error_initializing_sodium");
        exit(1);
    }
    unsigned int i = 1;
    if (max_levels == 1) return max_levels;
    while (i < max_levels) {
        if (randombytes_uniform(10) > 4) i++;
        else break;
    }
    return i;
}

void insert_mock(SList *self, double val) {
    PStack *pointer_stack = traverse_mock(self, val);
    unsigned int random_height = random_height_mock(self->max_levels);
    print_divider();
    printf("%d\n", random_height);
    print_divider();
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
    self->length++;
}

void print_mock(SList *self) {
    SListNode *a = self->top_left;
    SListNode *it = a;
    for (unsigned int i = 0; i < self->max_levels; i++) {
        printf("l_%d|\t", i);
        while (it != NULL) {
            printf("%f\t", it->val);
            it = it->next;
        }
        printf("\n");
        it = a->bottom;
        a = it;
    }
}