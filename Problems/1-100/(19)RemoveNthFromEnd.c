struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode** array = NULL;
    int count = 0;
    struct ListNode* current = head;

    while (current) {
        count++;
        array = realloc(array, count * sizeof(struct ListNode*));
        array[count - 1] = current;
        current = current->next;
    }

    int indexToRemove = count - n;

    if (indexToRemove == 0) {
        struct ListNode* newHead = head->next;
        free(head);
        free(array);
        return newHead;
    }

    struct ListNode* toRemove = array[indexToRemove];
    array[indexToRemove - 1]->next = toRemove->next;
    free(toRemove);
    free(array);

    return head;
}