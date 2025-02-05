#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* storage = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* out = storage;
    out->val = -99999;
    out->next = NULL;
    while(head){
        if(out->val != head->val){
            out->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            out = out->next;
            out->val = head->val;
            out->next = NULL;
        }
        head = head->next;
    }

    struct ListNode* result = storage->next;
    free(storage);
    return result;
}