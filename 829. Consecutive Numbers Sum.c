/*
 * Link: https://leetcode.com/problems/consecutive-numbers-sum/
 * Problem: 829. Consecutive Numbers Sum
 * */

int consecutiveNumbersSum(int n){
    int ans = 0, i = 1;
    
    while (n > 0){
        n -= i;
        ans = (n % i) == 0 ? ans + 1 : ans;
        i++;
    }
    
    return ans;
}

