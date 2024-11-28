/*
Problem: 2290. Minimum Obstacle Removal to Reach Corner
Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
*/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return d;
            }

            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                int nd = d + grid[x][y];
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, nx, ny});
                }
            }

        }

        return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];
    }
};
