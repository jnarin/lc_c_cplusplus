/*
Problem: 1979. Find Greatest Common Divisor of Array
Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int gcd(int a, int b) {
    int result = MINVAL(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        
        result--;
    }

    return result;
}

int findGCD(int* nums, int numsSize) {
    int mn = INT_MAX, mx = INT_MIN, i;
    
    for (i = 0; i < numsSize; i++) {
        mn = MINVAL(mn, nums[i]);
        mx = MAXVAL(mx, nums[i]);
    }
    
    return gcd(mn, mx);
}
