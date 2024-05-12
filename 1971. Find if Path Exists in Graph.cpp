/*
 * Problem: 1971. Find if Path Exists in Graph
 * Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
 * */

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination){
            return true;
        }

        unordered_map<int, unordered_set<int>> m;
        for (auto& it : edges){
            m[it[0]].insert(it[1]);
            m[it[1]].insert(it[0]);
        }

        queue<int> q;
        unordered_set<int> visited;
        q.push(source);


        while(q.size()){
            int t = q.front(); q.pop();

            if (m[t].find(destination) != m[t].end()){
                return true;
            }

            visited.insert(t);

            for (auto& it : m[t]){
                if (visited.find(it) == visited.end()){
                    q.push(it);
                }
            }
        }

        return false;

    }
};
