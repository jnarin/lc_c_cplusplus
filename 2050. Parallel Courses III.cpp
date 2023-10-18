class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        vector<int> inDegree(n), dist(time);
        queue<int> q;
        int u, v, i;
        
        for (auto &it : relations){
            u = it[0] - 1;
            v = it[1] - 1;
            graph[u].push_back(v);
            inDegree[v]++;
        }

        for (i = 0; i < n; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        while (q.size()){
            u = q.front();
            q.pop();

            for (auto &it : graph[u]){
                dist[it] = max(dist[it], dist[u] + time[it]);
                if (--inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        int ans = INT_MIN;

        for (auto &it : dist){
            ans = max(ans, it);
        }

        return ans;
    }
};