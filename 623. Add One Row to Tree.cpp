/*
 * Problem: 623. Add One Row to Tree
 * Link: https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr){
            return root;
        }

        if (depth == 1){
            TreeNode *r = new TreeNode(val, root, nullptr);
            return r;
        }

        int d = maxDepth(root) + 1;
        queue<TreeNode *> q;

        q.push(root);
        for (int i = 1; i < d; i++){
            int s = q.size();

            if (i > depth){
                break;
            }

            for (int j = 0; j < s; j++){
                TreeNode *t = q.front();
                q.pop();

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);


                if (i == depth - 1){
                    TreeNode *l = new TreeNode(val, t->left, nullptr);
                    TreeNode *r = new TreeNode(val, nullptr, t->right);
                    t->left = l;
                    t->right = r;
                }
            }
        }

        return root;
    }

private:
    int maxDepth(TreeNode *root){
        if (root){
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        } else {
            return 0;
        }
    }
};
