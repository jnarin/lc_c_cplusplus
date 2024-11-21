/*
Problem: 2257. Count Unguarded Cells in the Grid
Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
*/

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    int ans = 0, i, j;
    char grid[m][n], left[m][n], right[m][n], up[m][n], down[m][n], lastCell;

    memset(grid, 0, sizeof(grid));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));

    for (i = 0; i < guardsSize; i++) {
        grid[guards[i][0]][guards[i][1]] = 'G';
    }

    for (i = 0; i < wallsSize; i++) {
        grid[walls[i][0]][walls[i][1]] = 'W';
    }

    for (i = 0; i < m; i++) {
        lastCell = 0;

        for (j = 0; j < n; j++) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                lastCell = grid[i][j];
            } else {
                left[i][j] = lastCell;
            }
            
        }

        lastCell = 0;
        for (j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                lastCell = grid[i][j];
            } else {
                right[i][j] = lastCell;
            }
        }
    }

    for (j = 0; j < n; j++) {
        lastCell = 0;

        for (i = 0; i < m; i++) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                lastCell = grid[i][j];
            } else {
                up[i][j] = lastCell;
            }
        }

        lastCell = 0;
        for (i = m - 1; i >= 0; i--) {
            if (grid[i][j] == 'W' || grid[i][j] == 'G') {
                lastCell = grid[i][j];
            } else {
                down[i][j] = lastCell;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 0 
                && (left[i][j] != 'G' && right[i][j] != 'G' && up[i][j] != 'G' && down[i][j] != 'G')) {
                ans++;
            }
        }
    }

    return ans;
}
