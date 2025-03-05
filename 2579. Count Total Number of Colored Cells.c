/*
Problem: 2579. Count Total Number of Colored Cells
Link: https://leetcode.com/problems/count-total-number-of-colored-cells/
*/
long long coloredCells(int n) {
    return ((long long)n * n) + ((long long)(n - 1) * (n - 1));
}
