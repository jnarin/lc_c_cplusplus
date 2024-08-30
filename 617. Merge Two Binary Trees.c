/*
Problem: 617. Merge Two Binary Trees
Link: https://leetcode.com/problems/merge-two-binary-trees/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return NULL;
    }
    
    struct TreeNode *mergedRoot = calloc(1, sizeof(struct TreeNode));
    mergedRoot->val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
    mergedRoot->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL);
    mergedRoot->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
    
    return mergedRoot;
}
