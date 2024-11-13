/*
Problem: 2824. Count Pairs Whose Sum is Less than Target
Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int countPairs(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(int), incrCmp);

    int ans = 0, left = 0, right = numsSize - 1;

    while (left < right) {
        if (nums[left] + nums[right] < target) {
            ans += right - left;
            left++;
        } else {
            right--;
        }
    }
    
    return ans;
}
