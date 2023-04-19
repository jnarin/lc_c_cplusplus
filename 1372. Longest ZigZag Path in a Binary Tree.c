/*
Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/
Problem: 1372. Longest ZigZag Path in a Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? a : b;    })

static void dfs(struct TreeNode *root, int l, int r, int *ans){
    if (root == NULL){
        return;
    }
    
    *ans = MAX_VAL(*ans, MAX_VAL(l, r));
    dfs(root->left, r + 1, 0, ans);
    dfs(root->right, 0, l + 1, ans);
}

int longestZigZag(struct TreeNode* root){
    int ans = 0;
    dfs(root, 0, 0, &ans);
    return ans;
}