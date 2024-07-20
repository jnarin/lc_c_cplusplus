/*
Problem: 2096. Step-By-Step Directions From a Binary Tree Node to Another
Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, d;
        
        findLCA(root, startValue, s);
        findLCA(root, destValue, d);
        
        while (s.size() && d.size() && s.back() == d.back()) {
            s.pop_back();
            d.pop_back();
        }
        
        reverse(d.begin(), d.end());
        return string(s.size(), 'U') + d;
    }
    
private:
    bool findLCA(TreeNode *root, int val, string& path) {
        if (val == root->val) {
            return true;
        }
        
        if (root->left && findLCA(root->left, val, path)){
            path.push_back('L');
        } else if (root->right && findLCA(root->right, val, path)) {
            path.push_back('R');
        }
        
        return path.empty() == false;
    }
    
};
