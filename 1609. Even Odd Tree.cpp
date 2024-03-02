/*
 * Link: https://leetcode.com/problems/even-odd-tree/
 * Problem: 1609. Even Odd Tree
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
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr){
            return false;
        }

        queue<TreeNode *> q;
        int i = 0, j;
        q.push(root);

        while (q.size()) {
            int sz = q.size();
            vector<int> t;

            for (j = 0; j < sz; j++){
                TreeNode *tmp = q.front();
                q.pop();

                t.push_back(tmp->val);

                if (tmp->left){
                    q.push(tmp->left);
                }

                if (tmp->right){
                    q.push(tmp->right);
                }
            }


            set<int> s(t.begin(), t.end());
            if (s.size() != t.size()){
                // Not in strict sorted order
                return false;
            }

            if ((i & 1) == 0){
                for (auto &it : t){
                    if ((it & 1) == 0){
                        return false;
                    }
                }
                // Should have odd numbers in ascending order
                if (!is_sorted(t.begin(), t.end())){
                    return false;
                }
            } else {
                for (auto &it : t){
                    if ((it & 1) == 1){
                        return false;
                    }
                }
                // Should have even numbers in descending order
                reverse(t.begin(), t.end());
                if (!is_sorted(t.begin(), t.end())){
                    return false;
                }
            }

            i++;

        }

        return true;
    }
};

