/*
Problem: 974. Subarray Sums Divisible by K
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/

int subarraysDivByK(int* nums, int numsSize, int k){
    int ans, prefix, count[k], i;
    memset(count, 0, sizeof count);
    ans = prefix = 0;

    count[0] = 1;

    for (int i = 0; i < numsSize; i++){
        prefix = (prefix + nums[i] % k + k) % k;
        ans += count[prefix];
        count[prefix]++;
    }

    return ans;
}