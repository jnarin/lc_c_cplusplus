/*
Problem: 2331. Evaluate Boolean Binary Tree
Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if (root->val < 2) {
        return root->val;
    }

    if (root->val == 2) {
        return evaluateTree(root->left) || evaluateTree(root->right);
    }

    return evaluateTree(root->left) && evaluateTree(root->right);
}