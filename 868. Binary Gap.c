/*
Link: https://leetcode.com/problems/binary-gap/
Problem: 868. Binary Gap
*/

int binaryGap(int n){
    int ans = 0, d;
    
    for (d = -32; n; n >>= 1, d++) {
        if (n & 1) {
            ans = d > ans ? d : ans;
            d = 0;
        }
    }

    return ans;
}