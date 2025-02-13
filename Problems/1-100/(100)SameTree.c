#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Recursive(struct TreeNode* p, struct TreeNode* q, bool* same){
    if(!*same) return;
    if (!p && !q) return;
    if((!p && q) || (p && !q)){
        *same = false;
        return;
    }
    if(p->val != q->val){
        *same = false;
        return;
    }
    Recursive(p->left,q->left,same);
    Recursive(p->right,q->right,same);
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool same = true;

    Recursive(p,q, &same);

    return same;
}