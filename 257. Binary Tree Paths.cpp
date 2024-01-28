/*
 * Link: https://leetcode.com/problems/binary-tree-paths/
 * Problem: 257. Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        inorder(root, path, ans);
        return ans;
    }

private:
    void inorder(TreeNode* root, string path, vector<string>& ans) {
        if (root) {
            path += to_string(root->val);

            if (root->left == nullptr && root->right == nullptr) {
                ans.push_back(path);
                return;
            }

            path += "->";

            inorder(root->left, path, ans);
            inorder(root->right, path, ans);
        }
    }
};

