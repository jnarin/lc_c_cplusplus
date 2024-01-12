/*
Link: https://leetcode.com/problems/range-sum-of-bst/
Problem: 938. Range Sum of BST
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    int ans = 0;
    
    if (root) {
        if (root->val >= low && root->val <= high) {
            ans +=root->val;
        }
        
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
    
    return ans;
}