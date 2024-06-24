/*
Problem: 552. Student Attendance Record II
Link: https://leetcode.com/problems/student-attendance-record-ii/
*/

#define MOD ((int)(1e9 + 7))

static int eligibleCombinations(int n, int (*memo)[2][3], int tA, int cL) {
    
    if (tA >= 2 || cL >= 3) {
        return 0;
    }
    
    if (n == 0) {
        return 1;
    }

    if (memo[n][tA][cL] != -1) {
        return memo[n][tA][cL];
    }
    
    int count = eligibleCombinations(n - 1, memo, tA, 0);
    count = (count + eligibleCombinations(n - 1, memo, tA + 1, 0)) % MOD;
    count = (count + eligibleCombinations(n - 1, memo, tA, cL + 1)) % MOD;
    
    memo[n][tA][cL] = count;
    
    return count;
}

int checkRecord(int n){
    int memo[n + 1][2][3], i, j, k;
    
    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    
    return eligibleCombinations(n, memo, 0, 0);
}