/*
Problem: 1646. Get Maximum in Generated Array
Link: https://leetcode.com/problems/get-maximum-in-generated-array/
*/

int getMaximumGenerated(int n) {
    if (n < 2) {
        return n;
    }

    int nums[n + 1], maxVal = INT_MIN;

    nums[0] = 0;
    nums[1] = 1;
    
    for (int i = 2; i < n + 1; i++) {
        nums[i] = (i & 1) ?  nums[i / 2] + nums[i / 2 + 1] : nums[i / 2];
        maxVal = nums[i] > maxVal ? nums[i] : maxVal;
    }
    
    return maxVal;
}
