/*
Link: https://leetcode.com/problems/integer-break/
Problem: 343. Integer Break
*/
int integerBreak(int n){
    int ans = 1;
    
    if (n == 2){
        return 1;
    }
    
    if (n == 3){
        return 2;
    }
    
    for (; n > 4; n -= 3){
        ans *= 3;
    }
    
    ans *= n;
    
    return ans;
}