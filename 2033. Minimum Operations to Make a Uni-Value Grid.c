/*
Problem: 2033. Minimum Operations to Make a Uni-Value Grid
Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int n = gridSize, m = gridColSize[0], a[n * m], i, j;
    int median, ans = 0, diff;

    for (i= 0; i < n; i++){
        for (j = 0; j < m; j++){
            a[i*m+j] = grid[i][j];
        }
    }

    qsort(a, n * m, sizeof(int), incrCmp);

    median = a[n*m/2];
    
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            diff = abs(a[i*m+j] - median);

            if (diff % x != 0){
                return -1;
            }

            ans += diff / x;
        }
    }

    return ans;
}
