/*
Problem: 145. Binary Tree Postorder Traversal
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_NODES_NUM   (101)

static void traverse(struct TreeNode *root, int *ans, int *idx)
{
    if (root) {
        traverse(root->left, ans, idx);
        traverse(root->right, ans, idx);
        ans[(*idx)++] = root->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = calloc(MAX_NODES_NUM, sizeof(int)), idx = 0;
    
    traverse(root, ans, &idx);
    *returnSize = idx;

    return ans;
}
