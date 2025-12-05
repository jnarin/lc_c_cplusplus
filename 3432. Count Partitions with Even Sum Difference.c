/*
Problem: 3432. Count Partitions with Even Sum Difference
Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
*/

int countPartitions(int* nums, int numsSize) {
    inline int arraySum() {
        int i, ans = 0;

        for (i = 0; i < numsSize; i++) {
            ans += nums[i];
        }

        return ans;
    }
    
    return (arraySum() & 1) ? 0 : numsSize - 1;
}
