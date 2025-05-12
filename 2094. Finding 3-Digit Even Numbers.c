/*
Problem: 2094. Finding 3-Digit Even Numbers
Link: https://leetcode.com/problems/finding-3-digit-even-numbers/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    int *ans = calloc(1000, sizeof(int)), i, map[10] = {0}, n, idx = 0;

    for (i = 0; i < digitsSize; i++) {
        map[digits[i]]++;
    }

    for (n = 100; n < 1000; n += 2) {
        int tMap[10] = {0}, m = n;

        while (m) {
            tMap[m % 10]++;
            m /= 10;
        }

        bool f = true;

        for (i = 0; i < 10; i++) {
            if (tMap[i] && (tMap[i] > map[i])) {
                f = false;
                break;
            }
        }

        if (f) {
            ans[idx++] = n;
        }
    }
    
    *returnSize = idx;
    return ans;
}
