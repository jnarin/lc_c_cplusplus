/*
Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
Problem: 1319. Number of Operations to Make Network Connected
Approach:
Use the provided hints.
1. As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.
2. Use DFS to determine the number of isolated computer clusters.
*/
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        /* Hint 1 - check number of connections */
        if (connections.size() < (n - 1)){
            return -1;
        }
        
        vector<vector<int>> graph(n);
        int ans = 0;
        unordered_set<int> visited;
        int u, v, i;
        
        for (auto &c : connections){
            u = c[0];
            v = c[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        /* Hint 2 - use DFS to identify isolated clusters */
        for (i = 0; i < n; i++){
            if (visited.insert(i).second){
                dfs(graph, i, visited);
                ans++; 
            }
        }
        
        return ans - 1;
    }
    
private:
    void dfs(vector<vector<int>> &graph, int u, unordered_set<int> &visited){
        for (auto &v : graph[u]){
            if (visited.insert(v).second){
                dfs(graph, v, visited);
            }
        }
    }
};