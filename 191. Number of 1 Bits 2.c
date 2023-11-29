/*
Link: https://leetcode.com/problems/number-of-1-bits/
Problem: 191. Number of 1 Bits
*/

int hammingWeight(uint32_t n) {
    int ans = 0;
    
    while (n){
        ans += n & 1 ? 1 : 0;
        n >>= 1;
    }
   
    return ans;
}