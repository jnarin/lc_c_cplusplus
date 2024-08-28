/*
Problem: 1905. Count Sub Islands
Link: https://leetcode.com/problems/count-sub-islands/
*/

struct grids {
    int **grid1, grid1Size, grid1ColSize;
    int **grid2, grid2Size, grid2ColSize;
};

static int dfs(struct grids *g, int i, int j) {
    if (i < 0 || i >= g->grid2Size || j < 0 || j >= g->grid2ColSize) {
        return 1;
    }
    
    if (g->grid2[i][j] != 1) {
        return 1;
    }
    
    g->grid2[i][j] = 2;
    
    return dfs(g, i + 1, j) & dfs(g, i, j + 1) & dfs(g, i - 1, j) & dfs(g, i, j - 1) & g->grid1[i][j];
}

int countSubIslands(int** grid1, int grid1Size, int* grid1ColSize, int** grid2, int grid2Size, int* grid2ColSize) {
    int ans = 0, i, j;
    struct grids g;
    
    g.grid1 = grid1;
    g.grid1Size = grid1Size;
    g.grid1ColSize = grid1ColSize[0];
    g.grid2 = grid2;
    g.grid2Size = grid2Size;
    g.grid2ColSize = grid2ColSize[0];
    
    for (i = 0; i < g.grid2Size; i++) {
        for (j = 0; j < g.grid2ColSize; j++) {
            if (g.grid2[i][j] == 1) {
                ans += dfs(&g, i, j);
            }
        }
    }
    
    return ans;
}
