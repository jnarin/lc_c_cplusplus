/*
Link: https://leetcode.com/problems/equal-row-and-column-pairs/
Problem: 2352. Equal Row and Column Pairs
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> m;
        int i, j;
        int M = grid.size(), N = grid[0].size();
        int ans = 0;
        
        for (i = 0; i < M; i++){
            string t = "";
            
            for (j = 0; j < N; j++){
                t += to_string(grid[i][j]);
                t += "-";
            }
            
            m[t]++;
        }
        
        for (j = 0; j < N; j++){
            string t = "";
            
            for (i = 0; i < M; i++){
                t += to_string(grid[i][j]);
                t += "-";
            }
            
            if (m.find(t) != m.end()){
                ans += m[t];
            }
        }
        
        return ans;
    }
};