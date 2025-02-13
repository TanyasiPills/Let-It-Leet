#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int Recursive(struct TreeNode* current, int depth){
    if(!current) return depth;
    depth++;
    int left = Recursive(current->left, depth);
    int right = Recursive(current->right, depth);
    return (left> right) ? left : right;
}

int maxDepth(struct TreeNode* root) {
    return Recursive(root, 0);
}