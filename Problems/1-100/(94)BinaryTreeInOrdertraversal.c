#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void Recursive(struct TreeNode* current, int* array, int* last){
    if(!current) return;
    Recursive(current->left, array, last);
    array[(*last)++] = current->val;
    Recursive(current->right, array, last);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* array = (int*)malloc(*returnSize * sizeof(int));
    int last = 0, *ptr = &last;

    Recursive(root, array, ptr);

    return array;
}