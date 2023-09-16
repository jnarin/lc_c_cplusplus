/*
 * Link: https://leetcode.com/problems/path-with-minimum-effort/
 * Problem: 1631. Path With Minimum Effort
 * */

struct T{
    int x, y, d;
    T(int x, int y, int d) : x(x), y(y), d(d)   {}
};

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int M = heights.size(), N = heights[0].size();
            vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

            auto compare = [](const T &a, const T &b) { return a.d > b.d;};
            priority_queue<T, vector<T>, decltype(compare)> pq(compare);
            vector<vector<int>> diff(M, vector<int>(N, INT_MAX));
            vector<vector<int>> visited(M, vector<int>(N, false));

            pq.emplace(0, 0, 0);
            diff[0][0] = 0;

            while (pq.size()){
                auto [x, y, d] = pq.top();
                pq.pop();

                if (x == M - 1 && y == N - 1){
                    return d;
                }

                visited[x][y] = true;

                for (int k = 0; k < dirs.size(); k++){
                    int dx = x + dirs[k].first, dy = y + dirs[k].second;
                    if (dx < 0 || dx >= M || dy < 0 || dy >= N){
                        continue;
                    }

                    if (visited[dx][dy] == true){
                        continue;
                    }

                    int newDiff = abs(heights[x][y] - heights[dx][dy]);
                    int maxDiff = max(diff[x][y], newDiff);

                    if (diff[dx][dy] > maxDiff){
                        diff[dx][dy] = maxDiff;
                        pq.emplace(dx, dy, maxDiff);
                    }
                }
            }

            assert(0);
        }
};
