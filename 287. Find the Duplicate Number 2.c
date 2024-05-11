/*
 * Problem: 287. Find the Duplicate Number
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 * */

int findDuplicate(int* nums, int numsSize) {
    int slow, fast;

    slow = nums[nums[0]];
    fast = nums[nums[nums[0]]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
