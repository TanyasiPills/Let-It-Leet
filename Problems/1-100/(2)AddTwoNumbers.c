#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode d;
    struct ListNode* listptr = &d;
    struct ListNode* result = listptr;
    int leftover = 0;
    while (l1 || l2 || leftover) {
        int sum = leftover;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        leftover = sum / 10;
        sum %= 10;
        listptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        listptr = listptr->next;
        listptr->val = sum;
        listptr->next = NULL;
    }
    return d.next;
}