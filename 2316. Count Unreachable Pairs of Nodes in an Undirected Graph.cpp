/*
Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
Problem: 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
Approach:
Implememntation of the hints provided, using DFS
*/
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        int u, v, i;
        
        for (auto &e : edges){
            u = e[0];
            v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        long long ans = 0, notReachable = n, reachable;
        vector<bool> visited(n, false);
        
        for (i = 0; i < n; i++){
            reachable = dfs(graph, i, visited);
            notReachable -= reachable;
            ans = ans + (notReachable * reachable);
        }
        
        return ans;
    }
private:
    long long dfs(vector<vector<int>> &graph, int u, vector<bool> &visited){
        if (visited[u]){
            return 0;
        }
        
        visited[u] = true;
        
        int t = 1;
        for (auto &v : graph[u]){
            t += dfs(graph, v, visited);
        }
        
        return t;
    }
};
