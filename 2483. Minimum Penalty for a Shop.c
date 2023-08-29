/*
Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/
Problem: 2483. Minimum Penalty for a Shop
*/
int bestClosingTime(char * customers){
    int ans, profit, maxProfit, len = strlen(customers), i;
    ans = profit = maxProfit - 0;
    
    for (i = 0; i < len; i++){
        profit += customers[i] == 'Y' ? 1 : -1;
        if (profit > maxProfit){
            maxProfit = profit;
            ans = i + 1;
        }
    }

    return ans;
}