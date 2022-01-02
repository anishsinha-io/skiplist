#include "slist/slist-util.h"
#include "slist/models.h"
#include <sodium.h>
#include <stdlib.h>
#include <math.h>

unsigned int recalculate_max_levels(unsigned int length) {
    unsigned int new_max_levels = (unsigned int) (log(length) / log(2));
    return new_max_levels == 0 ? 1 : new_max_levels;
}


unsigned int random_height(unsigned int max_levels) {
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

SListUtil *new_slist_util() {
    SListUtil *new_slist_util = malloc(sizeof(SListUtil));
    new_slist_util->random_height = random_height;
    new_slist_util->recalculate_max_levels = recalculate_max_levels;
    return new_slist_util;
}