/*
Problem: 960. Delete Columns to Make Sorted III
Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
*/

int minDeletionSize(char** strs, int strsSize) {
    int n = strlen(strs[0]), i, j, f[n];

    for (i = 0; i < n; i++) {
        f[i] = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            int k, canExtend = 1;
            for (k = 0; k < strsSize; k++) {
                if (strs[k][j] > strs[k][i]) {
                    canExtend = 0;
                    break;
                }
            }
            
            if (canExtend) {
                if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                }
            }
        }
    }

    int maxLen = 0;
    for (i = 0; i < n; i++) {
        if (f[i] > maxLen) {
            maxLen = f[i];
        }
    }   

    return n - maxLen;    
    
}
