/*
Problem: 1038. Binary Search Tree to Greater Sum Tree
Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void convertBstToGst(struct TreeNode *root, int *sum) {
    if (root) {
        convertBstToGst(root->right, sum);
        
        *sum += root->val;
        root->val = *sum;
        
        convertBstToGst(root->left, sum);
    }
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    
    convertBstToGst(root, &sum);
    
    return root;    
}