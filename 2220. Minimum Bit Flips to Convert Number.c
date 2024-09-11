/*
Problem: 2220. Minimum Bit Flips to Convert Number
Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
*/

static int bitSetCount(int n) {
    int c;
    
    for (c = 0; n; c++) {
        n &= n - 1;
    }
    
    return c;
}

int minBitFlips(int start, int goal) {
    int n = start ^ goal;
    
    return bitSetCount(n);
}
