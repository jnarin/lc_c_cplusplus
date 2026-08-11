/*
Problem: 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
Link: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
*/

int missingInteger(int* nums, int numsSize) {
    bool set[51] = {0};
    int i, ans = nums[0];

    for (i = 0; i < numsSize; i++) {
        set[nums[i]] = true;
    }
    
    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1] + 1) {
            break;
        }

        ans += nums[i];
    }

    while (ans <= 50 && set[ans]) {
        ans++;
    }

    return ans;
}
