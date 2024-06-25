/*
Problem: 1248. Count Number of Nice Subarrays
Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
*/


static int numberOfSubarraysAtMost(int* nums, int numsSize, int k) {
    int ans = 0, l, r;
    
    l = r = 0;
    
    while (r <= numsSize) {
        if (k >= 0) {
            ans += r - l;
            
            if (r == numsSize) {
                break;
            }

            if (nums[r] & 1) {
                k--;
            }

            r++;
        } else {
            if (nums[l] & 1) {
                k++;
            }

            l++;
        }
    } 
    
    return ans;
}

int numberOfSubarrays(int* nums, int numsSize, int k){
    return numberOfSubarraysAtMost(nums, numsSize, k) - 
        numberOfSubarraysAtMost(nums, numsSize, k - 1);

}