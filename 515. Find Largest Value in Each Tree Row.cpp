/*
 * Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * Problem: 515. Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr){
            return ans;
        }

        queue<TreeNode *> q;
        int s, i, t, j;
        TreeNode *node;
        int depth = getDepth(root);

        q.push(root);

        for (i = 0; i < depth; i++){
            s = q.size();
            t = INT_MIN;

            for (j = 0; j < s; j++){
                node = q.front();
                q.pop();

                if (node){
                    t = max(t, node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            ans.push_back(t);
        }

        return ans;
    }
private:
    int getDepth(TreeNode *root){
        return root ? 1 + max(getDepth(root->left), getDepth(root->right)) : 0;
    }

};
