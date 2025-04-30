/*
Problem: 1295. Find Numbers with Even Number of Digits
Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/

static int countDigits(int n) {
    int ans = 0;

    while (n) {
        ans++;
        n /= 10;
    }

    return ans;
}

int findNumbers(int* nums, int numsSize) {
    int ans = 0, i;

    for (i = 0; i < numsSize; i++) {
        ans += (countDigits(nums[i]) & 1) == 0;
    }

    return ans;
}
