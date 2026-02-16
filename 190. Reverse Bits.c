/*
Problem: 190. Reverse Bits
Link: https://leetcode.com/problems/reverse-bits/
*/

int reverseBits(int n) {
    int pos = 32, ans = 0;

    while (pos--) {
        ans <<= 1;
        ans |= n & 1;
        n >>= 1;
    }

    return ans;    
}
