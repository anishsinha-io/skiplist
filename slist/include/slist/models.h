#include <stdbool.h>

#ifndef SKIPLIST_MODELS_H
#define SKIPLIST_MODELS_H

/// `SIGN` is an enumeration used by the `create_sentinel` function
typedef enum SIGN {
    positive = 1, negative = -1
} SIGN;

/// `SListNode` defines the structure of a generic skip list node
typedef struct SListNode {
    double val;
    struct SListNode *prev;
    struct SListNode *next;
    struct SListNode *bottom;
    struct SListNode *top;
    bool is_sentinel;
} SListNode;

/// `PStackFrame` defines the structure of a generic pointer stack frame
typedef struct PStackFrame {
    SListNode *pointer;
    struct PStackFrame *next;
} PStackFrame;

/// `PStack` defines the structure of a generic pointer stack
typedef struct PStack {
    unsigned int total_capacity;
    unsigned int frame_count;
    PStackFrame *top;

    void (*push)(struct PStack *, SListNode *);
    void (*clear)(struct PStack *);
    bool (*is_empty)(const struct PStack *);
    bool (*is_full)(const struct PStack *);
    SListNode *(*pop)(struct PStack *);
    const SListNode *(*peek)(const struct PStack *);
    PStackFrame *(*create_frame)(SListNode *);
} PStack;

/// `SListUtil` defines the structure containing generic skip list utility methods, i.e. `random_height` and
/// `recalculate_max_levels`
typedef struct SListUtil {
    unsigned int (*random_height)(unsigned int);
    unsigned int (*recalculate_max_levels)(unsigned int);
} SListUtil;

/// `SList` defines the structure of a generic skip list
typedef struct SList {
    unsigned int length;
    unsigned int max_levels;
    unsigned int current_height;
    SListNode *top_left;
    SListNode *bottom_left;
    SListNode *top_right;
    SListNode *bottom_right;
    void (*insert)(struct SList *, double);
    void (*print)(const struct SList *);
    void (*print_metadata)(const struct SList *);
    void (*delete)(struct SList *, double);
    void (*destroy)(struct SList *);
    void (*rebalance_levels)(struct SList *);
    void (*add_level)(struct SList *);
    void (*remove_level)(struct SList *);
    SListNode *(*create_sentinel)(SIGN);
    SListNode *(*create_node)(double);
    SListNode *(*search)(const struct SList *, double);
    PStack *(*get_left_adjacent_pointers)(const struct SList *, double);
    SListUtil *util;
} SList;

#endif //SKIPLIST_MODELS_H
