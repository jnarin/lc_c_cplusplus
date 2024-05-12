/*
 * Problem: 200. Number of Islands
 * Link: https://leetcode.com/problems/number-of-islands/
 * */

static void dfs(char **grid, int r, int c, int m, int n){
    if (r < 0 || r >= m || c < 0 || c >= n){
        return;
    }

    if (grid[r][c] != '1'){
        return;
    }

    grid[r][c] = 'X';
    dfs(grid, r + 1, c, m, n);
    dfs(grid, r - 1, c, m, n);
    dfs(grid, r, c + 1, m, n);
    dfs(grid, r, c - 1, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize){

    int r, c, m, n, count = 0;
    m = gridSize;
    n = gridColSize[0];



    for (r = 0; r < m; r++){
        for (c = 0; c < n; c++){
            if (grid[r][c] == '1'){
                count++;
                dfs(grid, r, c, m, n);
            }
        }
    }

    return count;

}
