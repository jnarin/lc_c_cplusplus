/*
Problem: 2874. Maximum Value of an Ordered Triplet II
Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

long long maximumTripletValue(int* nums, int numsSize) {
    long long  ans = 0, diff = 0, max = 0, i;

    for (i = 0; i < numsSize; i++) {
        ans = MAXVAL(ans, diff * nums[i]);

        diff = MAXVAL(diff, (long long)max - nums[i]);

        max = MAXVAL(max, (long long)nums[i]);
    }
    
    return ans;
}
