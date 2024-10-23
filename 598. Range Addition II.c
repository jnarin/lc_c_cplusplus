/*
Problem: 598. Range Addition II
Link: https://leetcode.com/problems/range-addition-ii/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int minRow = m, minCol = n, i;

    for(i = 0; i < opsSize; i++){
        minRow = MINVAL(ops[i][0], minRow);
        minCol = MINVAL(ops[i][1], minCol);
    }

    return minRow * minCol;
}
