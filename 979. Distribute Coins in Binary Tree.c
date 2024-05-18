/*
 * Problem: 979. Distribute Coins in Binary Tree
 * Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int dfs(struct TreeNode *root, int *moves){
    if (root == NULL) {
        return 0;
    }

    int leftCoins = dfs(root->left, moves),
        rightCoins = dfs(root->right, moves);

    *moves = *moves + abs(leftCoins) + abs(rightCoins);

    return (root->val - 1) + leftCoins + rightCoins;
}

int distributeCoins(struct TreeNode* root){
    int ans = 0;

    dfs(root, &ans);

    return ans;
}
