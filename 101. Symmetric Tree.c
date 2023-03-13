/*
Link: https://leetcode.com/problems/symmetric-tree/
Problem: 101. Symmetric Tree
Approach:
Recursively check if the tree is mirrored around the root node
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static bool isSymmetricTree(struct TreeNode *a, struct TreeNode *b){
    if (a == NULL && b == NULL){
        return true;
    }
    
    if (a && b){
        if (a->val != b->val){
            return false;
        }
        
        return isSymmetricTree(a->left, b->right) && isSymmetricTree(a->right, b->left);
    }
    
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root){
        return isSymmetricTree(root->right, root->left);    
    }
    
    return true;
}