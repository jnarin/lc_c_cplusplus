/*
 * Link: https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * Problem: 501. Find Mode in Binary Search Tree
 * */

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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        int maxCount = 0;

        inorder(root, m, maxCount);

        vector<int> ans;

        for (auto &it : m){
            if (it.second == maxCount){
                ans.push_back(it.first);
            }
        }

        return ans;
    }

private:
    void inorder(TreeNode *root, unordered_map<int, int> &m, int &maxCount){
        if (root == nullptr){
            return;
        }

        inorder(root->left, m, maxCount);

        m[root->val]++;
        maxCount = max(m[root->val], maxCount);

        inorder(root->right, m, maxCount);
    }
};
