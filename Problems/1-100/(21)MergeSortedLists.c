struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *d = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* listptr = d;
    int index = 0;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            listptr->next = list1;
            list1 = list1->next;
        } else {
            listptr->next = list2;
            list2 = list2->next;
        }
        listptr = listptr->next;
    }
    
    if (list1) {
        listptr->next = list1;
    } else {
        listptr->next = list2;
    }

    struct ListNode* result = d->next;
    free(d);
    return result;
}