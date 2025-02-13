#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* Recursive(int* nums, int left, int right){
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    struct TreeNode* current = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    current->val = nums[mid];
    current->left = Recursive(nums, left, mid - 1);
    current->right = Recursive(nums, mid + 1, right);
    return current;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return Recursive(nums, 0, numsSize - 1);
}