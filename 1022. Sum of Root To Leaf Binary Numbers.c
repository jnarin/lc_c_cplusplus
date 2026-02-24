/*
Problem: 1022. Sum of Root To Leaf Binary Numbers
Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumRootToLeaf(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int sum = 0;
    int currentValue = 0;
    
    void dfs(struct TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        currentValue = (currentValue << 1) | node->val;
        
        if (node->left == NULL && node->right == NULL) {
            sum += currentValue;
        }
        
        dfs(node->left);
        dfs(node->right);
        
        currentValue >>= 1;
    }
    
    dfs(root);
    
    return sum;
}
