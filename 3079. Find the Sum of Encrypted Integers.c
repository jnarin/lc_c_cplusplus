/*
Problem: 3079. Find the Sum of Encrypted Integers
Link: https://leetcode.com/problems/find-the-sum-of-encrypted-integers/
*/


static int getMaxDigit(int n) {
    int max = 0, t;
    
    while (n) {
        t = n % 10;
        max = t > max ? t : max;
        n /= 10;
    }
    
    return max;
}

static int getNumDigits(int n) {
    int d;
    
    for (d = 0; n; d++) {
        n /= 10;
    }
    
    return d;
}

int sumOfEncryptedInt(int* nums, int numsSize) {
    int ans = 0, i;
    int d, m, n;
    
    for (i = 0; i < numsSize; i++) {
        d = getNumDigits(nums[i]);
        m = getMaxDigit(nums[i]);
        
        n = 0;
        
        while (d--) {
            n = (n * 10) + m;
        }
        
        ans += n;
    }
    
    return ans;
}