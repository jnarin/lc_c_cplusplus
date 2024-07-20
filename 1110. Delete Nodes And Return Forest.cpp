/*
Problem: 1110. Delete Nodes And Return Forest
Link: https://leetcode.com/problems/delete-nodes-and-return-forest/
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        unordered_set<int> deleteSet = {to_delete.begin(), to_delete.end()};
        
        dfs(root, deleteSet, true, ans);
        
        return ans;
    }
    
private:
    TreeNode *dfs(TreeNode*& root, const unordered_set<int>& toDeleteSet, bool isRoot, vector<TreeNode *>& ans) {
        if (root) {
            bool deleted = toDeleteSet.count(root->val);
            if (isRoot && deleted == false) {
                ans.push_back(root);
            }
            
            root->left = dfs(root->left, move(toDeleteSet), deleted, ans);
            root->right = dfs(root->right, move(toDeleteSet), deleted, ans);
            
            if (deleted == false) {
                return root;
            }
        }
        
        return nullptr;
    }
};
