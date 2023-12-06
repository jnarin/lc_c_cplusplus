/*
Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
Problem: 1716. Calculate Money in Leetcode Bank
*/

int totalMoney(int n) {
    int ans, start, currentBal, t, i;
    const int numDays = 7;
    
    ans = start = t = 0;
    
    for (i = 0; i < n; i++){
        if (i % numDays == 0){
            currentBal = start + 1;
            start = currentBal;
        } else {
            currentBal = t + 1;
        }
        
        t = currentBal;
        ans += currentBal;
    }
    
    return ans;
}