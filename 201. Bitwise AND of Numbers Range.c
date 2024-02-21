/*
Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/
Problem: 201. Bitwise AND of Numbers Range
*/


int rangeBitwiseAnd(int left, int right) {
    int count = 0;
    
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count++;
    }
    
    return left << count;    
}