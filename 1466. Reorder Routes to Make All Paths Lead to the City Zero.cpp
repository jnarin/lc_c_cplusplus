
/*
Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
Problem: 1466. Reorder Routes to Make All Paths Lead to the City Zero
Approach:
Use the hint provided.
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        
        for (auto &e : connections){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(-e[0]);
        }
        
        return dfs(graph, 0, -1);
    }
    
private:
    int dfs(vector<vector<int>> &graph, int u, int parent){
        int ans = 0;
        
        for (auto &v : graph[u]){
            if (abs(v) == parent){
                continue;
            }
            
            if (v > 0){
                ans++;
            }
            
            ans += dfs(graph, abs(v), u);
        }
        
        return ans;
    }
};