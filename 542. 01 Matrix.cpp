/*
 * Link: https://leetcode.com/problems/01-matrix/
 * Problem: 542. 01 Matrix
 * */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int M = mat.size(), N = mat[0].size();
        vector<int> dirs{0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> v(M, vector<bool>(N, false));

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (mat[i][j] == 0){
                    q.push({i, j});
                    v[i][j] = true;
                }
            }
        }

        while (q.size()){
            pair<int, int> t = q.front();
            q.pop();

            for (int k = 0; k < 4; k++){
                int x = t.first + dirs[k], y = t.second + dirs[k + 1];

                if (x < 0 || x >= M || y < 0 || y >= N){
                    continue;
                }

                if (v[x][y] == true){
                    continue;
                }

                mat[x][y] = mat[t.first][t.second] + 1;
                q.push({x, y});
                v[x][y] = true;
            }
        }

        return mat;
    }
};
