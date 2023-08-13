/*
 * Link:
 * Problem: 95. Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0){
            return {nullptr};
        }
        
        return solve(1, n);
    }
    
private:
    vector<TreeNode *> solve(int a, int b){
        if (a > b){
            return {nullptr};
        }
        
        vector<TreeNode *> ans;
        for (int i = a; i <= b; i++){
            for (TreeNode *l : solve(a, i - 1)){
                for (TreeNode *r : solve(i + 1, b)){
                    TreeNode *t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    ans.push_back(t);
                }
            }
        }
        
        return ans;
    }
};
