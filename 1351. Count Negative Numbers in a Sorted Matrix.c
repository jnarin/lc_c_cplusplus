/*
Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
Problem: 1351. Count Negative Numbers in a Sorted Matrix
*/
int countNegatives(int** grid, int gridSize, int* gridColSize){
    int ans = 0, i = gridSize - 1, j = 0;
    
    while (i >= 0 && j < gridColSize[i]){
        if (grid[i][j] < 0){
            ans += gridColSize[i] - j;
            i--;
        } else {
            j++;
        }
    }
    
    return ans;
}