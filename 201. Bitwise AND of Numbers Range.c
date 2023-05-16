/*
Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/
Problem: 201. Bitwise AND of Numbers Range
*/
int rangeBitwiseAnd(int left, int right){
    unsigned int i;
    int ans = INT_MAX;
    for (i = left; i <= right; i++){
        ans &= i;
        if (ans == 0){
            break;
        }
    }

    return ans;
}