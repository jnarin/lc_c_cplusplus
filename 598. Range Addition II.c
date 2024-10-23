/*
Problem: 598. Range Addition II
Link: https://leetcode.com/problems/range-addition-ii/
*/

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int minRow = m, minCol = n, i;

    for(i = 0; i < opsSize; i++){
        minRow = ops[i][0] < minRow ? ops[i][0] : minRow;
        minCol = ops[i][1] < minCol ? ops[i][1] : minCol;
    }

    return minRow * minCol;
}
