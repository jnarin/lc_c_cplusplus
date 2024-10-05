/*
Problem: 3300. Minimum Element After Replacement With Digit Sum
Link: https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b));

static int digitSum(int n) {
    int sum = 0;
    
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int minElement(int* nums, int numsSize) {
    int i;
    int ans = INT_MAX;
    
    for (i = 0; i < numsSize; i++) {
        ans = MINVAL(ans, digitSum(nums[i]));
    }
    
    return ans;
}
