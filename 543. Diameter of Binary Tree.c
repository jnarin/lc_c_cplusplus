/*
Link: https://leetcode.com/problems/diameter-of-binary-tree/
Problem: 543. Diameter of Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

static int x(struct TreeNode *root, int *ans){
    if (root == NULL){
        return 0;
    }
    
    int l = x(root->left, ans);
    int r = x(root->right, ans);
    
    *ans = MAXVAL(l + r, *ans);
    
    return 1 + (l > r ? l : r);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 0;
    x(root, &ans);
    return ans;
        

}