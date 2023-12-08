/*
Link: https://leetcode.com/problems/construct-string-from-binary-tree/
Problem: 606. Construct String from Binary Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_LEN ((int)(10e4 * 5))

static void tree2strExtract(struct TreeNode* root, char *ans, int *idx){
    int t;
    
    if (root){
        t = sprintf(&ans[*idx], "%d", root->val);
        *idx += t;
        
        if (root->left || root->right){
            ans[*idx] = '(';
            *idx += 1;
            tree2strExtract(root->left, ans, idx);
            ans[*idx] = ')';
            *idx += 1;
            
            if (root->right){
                ans[*idx] = '(';
                *idx += 1;
                tree2strExtract(root->right, ans, idx);
                
                ans[*idx] = ')';
                *idx += 1;
            }
        }
    }
}


char* tree2str(struct TreeNode* root) {
    
    char *ans = calloc(MAX_LEN + 1, sizeof(char));
    int idx = 0;
    
    tree2strExtract(root, ans, &idx);
    
    return ans;    
}