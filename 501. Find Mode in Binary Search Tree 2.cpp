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
        vector<int> ans;
        int count, maxCount;

        count = maxCount = 0;

        inorderGetMode(root, count, maxCount, ans);

        return ans;
    }

private:
    TreeNode *parent = nullptr;

    void inorderGetMode(TreeNode *root, int &count, int &maxCount, vector<int> &ans){
        if (root == nullptr){
            return;
        }

        inorderGetMode(root->left, count, maxCount, ans);

        if (parent && parent->val == root->val){
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount){
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        } else if (count == maxCount){
            ans.push_back(root->val);
        }

        parent = root;

        inorderGetMode(root->right, count, maxCount, ans);
    }
};
