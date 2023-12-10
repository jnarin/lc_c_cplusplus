/*
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Problem: 94. Binary Tree Inorder Traversal
 * */

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
#define MAX_NODES   (101)

static void inorder(struct TreeNode *root, int *ans, int *idx){
    if (root){
        inorder(root->left, ans, idx);

        ans[*idx] = root->val;
        *idx += 1;

        inorder(root->right, ans, idx);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *ans = calloc(MAX_NODES, sizeof(int));

    *returnSize = 0;

    inorder(root, ans, returnSize);

    return ans;
}

