/*
Problem: 3550. Smallest Index With Digit Sum Equal to Index
Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
*/

static int sumOfDigits(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int smallestIndex(int* nums, int numsSize) {
    int i, ans = -1;

    for (i = 0; i < numsSize; i++) {
        if (sumOfDigits(nums[i]) == i) {
            ans = i;
            break;
        }
    }
    
    return ans;
}
