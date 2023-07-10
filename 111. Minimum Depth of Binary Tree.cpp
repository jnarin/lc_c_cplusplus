/*
Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Problem: 111. Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.size()){
            ans++;
            int size = q.size();
            
            while (size){
                TreeNode *t = q.front();
                q.pop();

                if (t->left == nullptr && t->right == nullptr){
                    return ans;
                }
                
                if (t->left){
                    q.push(t->left);
                }

                if (t->right){
                    q.push(t->right);
                }

                size--;
            }
        }
        
        return ans;
    }
};