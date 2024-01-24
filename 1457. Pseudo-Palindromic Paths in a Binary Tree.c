/*
Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
Problem: 1457. Pseudo-Palindromic Paths in a Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool checkPalindrome(int *map) {
    int i;
    bool gotOneOddCountElement = false;
    
    for (i = 0; i < 10; i++) {
        if (map[i] & 1) {
            if (gotOneOddCountElement) {
                return false;
            }
            
            gotOneOddCountElement = true;
        }
    }
    
    return true;
}

static void dfs(struct TreeNode *root, int *ans, int *map) {
    if (root) {
        map[root->val] += 1;
        
        if (root->left == NULL && root->right == NULL) {
            if (checkPalindrome(map)) {
                *ans += 1;
            }
        }
        
        dfs(root->left, ans, map);
        dfs(root->right, ans, map);
        
        map[root->val] -= 1;
    }
}

int pseudoPalindromicPaths (struct TreeNode* root) {
    int map[10] = {0}, ans = 0;
    
    dfs(root, &ans, map);
    
    return ans;    
}