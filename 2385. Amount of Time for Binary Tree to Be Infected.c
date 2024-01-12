/*
Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
Problem: 2385. Amount of Time for Binary Tree to Be Infected
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
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int traverse(struct TreeNode* root, int start, int *ans) {
    if (root == NULL) {
        return 0;
    }
    
    int l = traverse(root->left, start, ans), r = traverse(root->right, start, ans);
    
    if (root->val == start) {
        *ans = MAXVAL(*ans, MAXVAL(l, r));
        return -1;
    }
    
    if (l >= 0 && r >= 0) {
        return MAXVAL(l, r) + 1;
    }
    
    *ans = MAXVAL(*ans, abs(l) + abs(r));
    
    return MINVAL(l, r) - 1;
}

int amountOfTime(struct TreeNode* root, int start) {
    int ans = 0;
    
    traverse(root, start, &ans);
    
    return ans;
}