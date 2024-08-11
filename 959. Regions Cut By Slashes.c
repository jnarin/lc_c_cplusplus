/*
Problem: 959. Regions Cut By Slashes
Link: https://leetcode.com/problems/regions-cut-by-slashes/
*/

static void dfs(int n, int g[n][n], int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return;
    }
    
    if (g[i][j] != 0) {
        return;
    }
    
    g[i][j] = 2;
    dfs(n, g, i + 1, j);
    dfs(n, g, i, j + 1);
    dfs(n, g, i - 1, j);
    dfs(n, g, i, j - 1);
}

int regionsBySlashes(char ** grid, int gridSize){
    int n = gridSize * 3, i, j;
    int g[n][n], ans = 0;
    
    memset(g, 0, sizeof(g));
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (grid[i][j] == '/') {
              g[i * 3][j * 3 + 2] = 1;
              g[i * 3 + 1][j * 3 + 1] = 1;
              g[i * 3 + 2][j * 3] = 1;
            } else if (grid[i][j] == '\\') {
              g[i * 3][j * 3] = 1;
              g[i * 3 + 1][j * 3 + 1] = 1;
              g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (g[i][j] == 0) {
                dfs(n, g, i, j);
                ans++;
            }
        }
    }
    
    return ans;
}
