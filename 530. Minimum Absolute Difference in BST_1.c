/*
Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
Problem: 530. Minimum Absolute Difference in BST
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MINVAL(a, b) \
({  __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static void inorder(struct TreeNode* root, int *ans, int *prev){
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, ans, prev);
    *ans = MINVAL(*ans, root->val - *prev);
    *prev = root->val;
    inorder(root->right, ans, prev);
    
}

int getMinimumDifference(struct TreeNode* root){
    int ans = INT_MAX, prev = -1e6;
    
    inorder(root, &ans, &prev);
    
    return ans;
}