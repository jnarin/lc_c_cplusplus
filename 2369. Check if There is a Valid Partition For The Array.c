/*
 * Link: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
 * Problem: 2369. Check if There is a Valid Partition For The Array
 * */


bool validPartition(int* nums, int numsSize){
    bool dp[numsSize + 1];
    memset(dp, 0, sizeof(dp));

    int i;

    dp[0] = true;
    dp[2] = nums[0] == nums[1];

    for (i = 3; i <= numsSize; i++){
        dp[i] = (dp[i - 2]
                 && nums[i - 2] == nums[i - 1])
            || (dp[i - 3]
                && ((nums[i - 3] == nums[i - 2]
                     && nums[i - 2] == nums[i - 1])
                || (nums[i - 3] == nums[i - 2] - 1
                    && nums[i - 2] == nums[i - 1] - 1)));
    }

    return dp[numsSize];
}
