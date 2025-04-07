/*
Problem: 416. Partition Equal Subset Sum
Link: https://leetcode.com/problems/partition-equal-subset-sum/
*/

bool canPartition(int* nums, int numsSize) {
	int sum = 0, i, j, target;
	
	for (i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	
	if (sum & 1) {
		return false;
	}
    
	target = sum / 2;
	
	bool dp[target + 1];
	memset(dp, 0, sizeof(dp));
	
	dp[0] = true;
	
	for (i = 0; i < numsSize; i++) {
		for (j = target; j >= nums[i]; j--) {
			dp[j] = (dp[j - nums[i]]) ? true : dp[j];
		}
	}
	
	return dp[target];
}
