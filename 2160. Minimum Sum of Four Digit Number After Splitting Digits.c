/*
Problem: 2160. Minimum Sum of Four Digit Number After Splitting Digits
Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minimumSum(int num) {
    int t[4], i;
    
    for (i = 0; i < 4; i++) {
        t[i] = num % 10;
        num /= 10;
    }
    
    qsort(t, 4, sizeof(int), incrCmp);
    
    int a = t[0] * 10 + t[2], b = t[1] * 10 + t[3];
    
    return a + b;
}
