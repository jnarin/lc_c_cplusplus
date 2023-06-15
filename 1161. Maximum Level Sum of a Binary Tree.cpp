/*
Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
Problem: 1161. Maximum Level Sum of a Binary Tree
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
    int maxLevelSum(TreeNode* root) {
        int i, level = 1;
        unordered_map<int, int> m;
        queue<TreeNode *> q;
        
        if (root == nullptr){
            return -1;
        }
        
        q.push(root);
        while (q.size()){
            int s = q.size(), sum = 0;
            for (i = 0; i < s; i++){
                TreeNode *t = q.front();
                q.pop();
                
                sum += t->val;
                if (t->right){
                    q.push(t->right);
                }
                
                if (t->left){
                    q.push(t->left);
                }
            }
            
            if (m.find(sum) == m.end()){
                m[sum] = level;
            }
            
            level++;
        }
        
        i = INT_MIN;
        for (auto &it : m){
            i = max(i, it.first);
        }
        
        return m[i];
        
    }
};