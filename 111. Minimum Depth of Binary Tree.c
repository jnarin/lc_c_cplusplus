/*
Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Problem: 111. Minimum Depth of Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MINVAL(a, b)  \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;    })

int minDepth(struct TreeNode* root){
    if (root == NULL){
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else if (root->right == NULL) {
        return 1 + minDepth(root->left);
    } else if (root->left == NULL) {
        return 1 + minDepth(root->right);
    }
    
    return 1 + MINVAL(minDepth(root->left), minDepth(root->right));
}