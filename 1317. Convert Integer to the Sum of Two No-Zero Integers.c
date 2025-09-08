/*
Problem: 1317. Convert Integer to the Sum of Two No-Zero Integers
Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
*/
bool numberHasZero(int n) {
    bool r = false;
    while (n){
        int t = n % 10;
        if (t == 0 && t != n){
            r = true;
            break;
        }
        n /= 10;
    }
    
    return r;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers(int n, int* returnSize) {
    int *ans = NULL;
    *returnSize = 0;
    
    for (int i = 1; i < n; i++){
        if (i + (n - i) == n){
            if (numberHasZero(i) == false && numberHasZero(n - i) == false){
                ans = calloc(2, sizeof(int));
                *returnSize = 2;

                ans[0] = i;
                ans[1] = n - i;

                break;
            }
        } 
    }        
    
    return ans;
}
