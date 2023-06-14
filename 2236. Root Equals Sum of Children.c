/* 
 * Link: https://leetcode.com/problems/root-equals-sum-of-children/
 * Problem: 2236. Root Equals Sum of Children
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool checkTree(struct TreeNode* root){    
    return root && (root->val == root->left->val + root->right->val) ? true : false;
}
