/*
Link: https://leetcode.com/problems/leaf-similar-trees/
Problem: 872. Leaf-Similar Trees
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_NODES (201)

static void traverse(struct TreeNode *root, int *t, int *i){
    if (root){
        if (root->left == NULL && root->right == NULL){
            t[*i] = root->val;
            *i = *i + 1;
        }

        traverse(root->left, t, i);
        traverse(root->right, t, i);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int t1[MAX_NODES] = {0}, t2[MAX_NODES] = {0};
    int i1 = 0, i2 = 0;

    traverse(root1, t1, &i1);
    traverse(root2, t2, &i2);

    return (i1 == i2) && (memcmp(t1, t2, sizeof(t1)) == 0);
}