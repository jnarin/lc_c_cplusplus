/*
 * Problem: 834. Sum of Distances in Tree
 * Link: https://leetcode.com/problems/sum-of-distances-in-tree/
 * */

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        vector<int> count(n, 1);
        vector<unordered_set<int>> adj(n);

        for (auto& it : edges){
            int x = it[0], y = it[1];
            adj[x].insert(y);
            adj[y].insert(x);
        }

        postorder(adj, 0, -1, count, ans);
        preorder(adj, 0, -1, count, ans);

        return ans;
    }

    void postorder(vector<unordered_set<int>>& adj, int node, int parent, vector<int>& count, vector<int>& ans){
        for (auto& child : adj[node]){
            if (child == parent){
                continue;
            }

            postorder(adj, child, node, count, ans);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }


    void preorder(vector<unordered_set<int>>& adj, int node, int parent, vector<int>& count, vector<int>& ans){
        for (auto& child : adj[node]){
            if (child == parent){
                continue;
            }

            ans[child] = ans[node] - count[child] + (adj.size() - count[child]);
            preorder(adj, child, node, count, ans);
        }
    }
};
