#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool Recursive(struct TreeNode* left, struct TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    return Recursive(left->left, right->right) && Recursive(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return Recursive(root->left, root->right);
}