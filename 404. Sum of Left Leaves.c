/*
Link: https://leetcode.com/problems/sum-of-left-leaves/
Problem: 404. Sum of Left Leaves
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root){
    int ans = 0;
    
    if (root != NULL){
        if (root->left == NULL){
            return sumOfLeftLeaves(root->right);
        }

        if (root->left->left == NULL && root->left->right == NULL){
            ans += root->left->val;
        } else {
            ans += sumOfLeftLeaves(root->left);
        }

        ans += sumOfLeftLeaves(root->right);
    }
    
    return ans;
}