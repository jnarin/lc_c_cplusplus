/*
Problem: 865. Smallest Subtree with all the Deepest Nodes
Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct nodeDepth {
    struct TreeNode *node;
    int depth;
};

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    struct nodeDepth dfs(struct TreeNode* root) {
        struct nodeDepth p = {NULL, 0};
        if (root == NULL) {
            return p;
        }

        struct nodeDepth l = dfs(root->left),
                         r = dfs(root->right);
        if (l.depth > r.depth) {
            p.node = l.node;
            p.depth = l.depth + 1;
            return p;
        } 

        if (l.depth < r.depth) {
            p.node = r.node;
            p.depth = r.depth + 1;
            return p;
        }

        p.node = root;
        p.depth = l.depth + 1;
        return p;
    } 

    return dfs(root).node;
}
