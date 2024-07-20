/*
Problem: 2196. Create Binary Tree From Descriptions
Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_set<int> children, parents;
        unordered_map<int, vector<pair<int, int>>> parentToChildren;
        
        for (auto& d : descriptions) {
            parents.insert(d[0]);
            parents.insert(d[1]);
            children.insert(d[1]);
            
            parentToChildren[d[0]].push_back({d[1], d[2]});
        }
        
        for (auto it = parents.begin(); it != parents.end();) {
            if (children.find(*it) != children.end()) {
                it = parents.erase(it);
            } else {
                it++;
            }
        }
        
        TreeNode *root = new TreeNode(*parents.begin());
        
        queue<TreeNode *> q;
        q.push(root);
        
        while (q.size()) {
            TreeNode *parent = q.front();
            q.pop();
            
            for (auto& childInfo : parentToChildren[parent->val]) {
                int val = childInfo.first, l = childInfo.second;
                
                TreeNode *child = new TreeNode(val);
                q.push(child);
                
                if (l) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        }
        
        return root;
    }
    
};
