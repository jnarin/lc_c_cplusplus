/*
Problem: 2415. Reverse Odd Levels of Binary Tree
Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void dfs(struct TreeNode *left, struct TreeNode *right, bool oddLevel) {
    if (left == NULL || right == NULL) {
        return;
    }
    
    if (oddLevel) {
        int t = left->val;
        left->val = right->val;
        right->val = t;
    }
    
    dfs(left->left, right->right, !oddLevel);
    dfs(left->right, right->left, !oddLevel);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    dfs(root->left, root->right, true);
    return root;
}
