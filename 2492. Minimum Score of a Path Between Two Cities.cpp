/*
Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
Problem: 2492. Minimum Score of a Path Between Two Cities
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> graph(n);
        queue<int> q;
        vector<bool> visited(n);
        int u, v, d;
        
        q.push(0);
        visited[0] = true;
        
        for (auto &t : roads){
            u = t[0] - 1;
            v = t[1] - 1;
            d = t[2];
            
            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }
        
        while (q.size()){
            u = q.front();
            q.pop();
            
            for (auto &[a, b] : graph[u]){
                ans = min(ans, b);
                if (visited[a] == true){
                    continue;
                }
                
                q.push(a);
                visited[a] = true;
            }
        }
        
        
        return ans;
        
    }
};