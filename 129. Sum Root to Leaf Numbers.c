/*
Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
Problem: 129. Sum Root to Leaf Numbers
Approach:
Perform DFS (recursion)
Pass previous path sum to DFS function
Multiply previous path sum by 10 and add current value
Sum the values of path sum for leaf nodes
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static void traverse(struct TreeNode *node, int prev, int *ans){
    if (node == NULL){
        return;
    }
    
    if (node->left == NULL && node->right == NULL){
        *ans = *ans + ((prev * 10) + node->val);
        return;
    }
    
    traverse(node->left, (prev * 10) + node->val, ans);
    traverse(node->right, (prev * 10) + node->val, ans);
}
int sumNumbers(struct TreeNode* root){
    int ans = 0;
    traverse(root, 0, &ans);
    return ans;

}