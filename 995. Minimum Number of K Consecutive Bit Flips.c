/*
Problem: 995. Minimum Number of K Consecutive Bit Flips
Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
*/

int minKBitFlips(int* nums, int numsSize, int k) {
    int ans = 0, f = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        if (i >= k && nums[i - k] == 2) {
            f--;
        }
        
        if ((f & 1) == nums[i]) {
            if (i + k > numsSize) {
                return -1;
            }
            
            ans++;
            f++;
            nums[i] = 2;
        }
    }
    
    return ans;
}