/*
 * Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
 * Problem: 847. Shortest Path Visiting All Nodes
 * */

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if (n < 2){
            return 0;
        }

        int all = (1 << n) - 1, mask, newMask, i, val, dist;
        set<pair<int, int>> visited;
        queue<pair<int, pair<int, int>>> q;

        for (i = 0; i < n; i++){
            mask = 1 << i;
            q.push({i, {0, mask}});
            visited.insert({i, mask});
        }

        while (q.size()){
            auto t = q.front();
            q.pop();

            val = t.first;
            dist = t.second.first;
            mask = t.second.second;

            for (auto &temp : graph[val]){
                newMask = mask | (1 << temp);
                if (newMask == all){
                    return dist + 1;
                } else if (visited.count({temp, newMask})){
                    continue;
                }

                visited.insert({temp, newMask});
                q.push({temp, {dist + 1, newMask}});
            }
        }

        return 0;
    }
};
