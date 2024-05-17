/*
Problem: 1325. Delete Leaves With a Given Value
Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct TreeNode *_removeLeafNodesHelper(struct TreeNode* root, int target, struct TreeNode* parent) {
    if (root == NULL) {
        return NULL;
    }
    
    root->left = _removeLeafNodesHelper(root->left, target, root);
    root->right = _removeLeafNodesHelper(root->right, target, root);
    
    if (root->left == NULL && root->right == NULL && root->val == target) {
        if (parent) {
            free(root);
        }
        
        return NULL;
    }
    
    return root;
}

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target) {
    return _removeLeafNodesHelper(root, target, NULL);
}