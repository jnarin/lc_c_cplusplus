/*
Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
Problem: 1026. Maximum Difference Between Node and Ancestor
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXVAL(a, b) \
({  __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b; })

#define MINVAL(a, b) \
({  __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a < _b ? _a : _b; })


struct minmaxPair_t {
    int min, max;
};

static int dfs(struct TreeNode *root, struct minmaxPair_t m) {
    if (root == NULL) {
        return m.max - m.min;
    }
    
    m.max = MAXVAL(root->val, m.max);
    m.min = MINVAL(root->val, m.min);
    
    return MAXVAL(dfs(root->left, m), dfs(root->right, m));
}

int maxAncestorDiff(struct TreeNode* root) {
    struct minmaxPair_t m = {.min = INT_MAX,
                             .max = INT_MIN};
    
    return dfs(root, m);
}