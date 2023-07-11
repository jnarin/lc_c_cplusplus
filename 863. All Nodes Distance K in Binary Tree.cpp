/*
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
Problem: 863. All Nodes Distance K in Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        
        queue<TreeNode *> q;
        q.push(target);
        
        set<TreeNode *> visited;
        visited.insert(target);
        
        vector<int> ans;
        
        int d = 0;
        while (q.size()){
            if (d == k){
                while(q.size()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            
            int s = q.size();
            while (s){
                TreeNode *t = q.front();
                q.pop();
                
                if (t->left && visited.find(t->left) == visited.end()){
                    q.push(t->left);
                    visited.insert(t->left);
                }
                
                if (t->right && visited.find(t->right) == visited.end()){
                    q.push(t->right);
                    visited.insert(t->right);
                }
                
                TreeNode *x = p[t];
                if (x && visited.find(x) == visited.end()){
                    q.push(x);
                    visited.insert(x);
                }
                
                s--;
            }
            
            d++;
        }
        
        return ans;
    }
    
private:
    unordered_map<TreeNode *, TreeNode *> p;
    
    void dfs(TreeNode *node, TreeNode *parent){
        if (node){
            p[node] = parent;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
};