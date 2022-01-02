#include "slist/models.h"
#include "slist/pstack.h"
#include "slist/slist.h"
#include "slist/mock.h"
#include "slist/util.h"
#include <stdio.h>

int main() {
    SList *list1 = new_slist();
    list1->insert(list1, 5);
    list1->insert(list1, 6);
    list1->insert(list1, 5.5);
    list1->insert(list1, 4);
    list1->insert(list1, 3.3);
    list1->insert(list1, 4.5);
    list1->insert(list1, 5.6);
    list1->insert(list1, 7.7);
    list1->insert(list1, 7);
    list1->insert(list1, 9);
    list1->print_metadata(list1);
    SListNode *it = list1->top_left;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    printf("\n");
    it = list1->top_left->bottom;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    printf("\n");
    it = list1->top_left->bottom->bottom;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    print_divider();
    list1->delete(list1, 7.7);
    list1->delete(list1, 3.3);
    list1->delete(list1, 4);
    list1->print_metadata(list1);
    it = list1->top_left;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    printf("\n");
    it = list1->top_left->bottom;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    printf("\n");
    it = list1->top_left->bottom->bottom;
    while (it != NULL) {
        printf("%f\t", it->val);
        it = it->next;
    }
    return 0;
}
