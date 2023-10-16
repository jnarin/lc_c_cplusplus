/*
Link: https://leetcode.com/problems/univalued-binary-tree/
Problem: 965. Univalued Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static bool isSameValue(struct TreeNode *node, int val){
    if (node){
        if (node->val != val){
            return false;
        }
        
        return isSameValue(node->left, val) && isSameValue(node->right, val);
    }
    
    return true;
}

bool isUnivalTree(struct TreeNode* root){
    if (root == NULL){
        return true;
    }
    
    return isSameValue(root, root->val);
}