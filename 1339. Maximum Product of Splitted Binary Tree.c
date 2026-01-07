/*
Problem: 1339. Maximum Product of Splitted Binary Tree
Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MAX3VAL(a, b, c) MAXVAL(MAXVAL(a, b), c)

static void treeSum(struct TreeNode *root, long long *total) {
    if (root == NULL) {
        return;
    }

    *total = *total + root->val;
    treeSum(root->left, total);
    treeSum(root->right, total);
}

static int sumUnder(struct TreeNode *root, long long total, long long *ans) {
    if (root == NULL) {
        return 0;
    }

    int sumLeft = sumUnder(root->left, total, ans),
        sumRight = sumUnder(root->right, total, ans);
    
    *ans = MAX3VAL(*ans, (total - sumLeft) * sumLeft, (total - sumRight) * sumRight);
    
    return sumLeft + sumRight + root->val;
} 

int maxProduct(struct TreeNode* root) {
    long long total = 0, ans = 0;
    const int MOD = (1e9 + 7);

    treeSum(root, &total);
    sumUnder(root, total, &ans);

    return ans  % MOD;    
}
