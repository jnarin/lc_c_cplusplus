/*
Link: https://leetcode.com/problems/number-of-1-bits/
Problem: 191. Number of 1 Bits
K&R Approach
*/

int hammingWeight(uint32_t n) {
    int ans;
    
    for (ans = 0; n; ans++){
        n &= (n - 1);
    }
    
    return ans;
}