/*
Problem: 2873. Maximum Value of an Ordered Triplet I
Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

long long maximumTripletValue(int* nums, int numsSize) {
    long long ans = 0, v;
    int i, j, k;

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            for (k = j + 1; k < numsSize; k++) {
                v = (long long)(nums[i] - nums[j]) * nums[k];
                ans = MAXVAL(ans, v);
            }
        }
    }

    return ans;    
}
