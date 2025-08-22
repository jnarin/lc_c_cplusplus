/*
Problem: 3195. Find the Minimum Area to Cover All Ones I
Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

struct point {
    int x, y;
};

int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize, i, j;
    struct point p1 = {m, n}, p2 = {0, 0};
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j]) {
                p1.x = MINVAL(p1.x, i);
                p1.y = MINVAL(p1.y, j);
                p2.x = MAXVAL(p2.x, i);
                p2.y = MAXVAL(p2.y, j);
            }
        }
    }

    return (p2.x - p1.x + 1) * (p2.y - p1.y + 1);
}

