/*
Link: https://leetcode.com/problems/find-bottom-left-tree-value/
Problem: 513. Find Bottom Left Tree Value
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        if (root == nullptr) {
            return ans;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.size()) {
            int s = q.size();
            bool l = true;
            
            for (int i = 0; i < s; i++) {
                TreeNode *t = q.front();
                q.pop();
                
                if (l) {
                    ans = t->val;
                    l = false;
                }
                
                if (t->left) {
                    q.push(t->left);
                }
                
                if (t->right) {
                    q.push(t->right);
                }
                
            }
        }
        
        return ans;   
    }
};