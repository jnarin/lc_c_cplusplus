/*
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Problem: 714. Best Time to Buy and Sell Stock with Transaction Fee
*/

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxProfit(int* prices, int pricesSize, int fee){
    int sell = 0, hold = INT_MIN, i;
    
    for (i = 0; i < pricesSize; i++){
        sell = MAXVAL(sell, prices[i] + hold);
        hold = MAXVAL(hold, sell - prices[i] - fee);
    }

    return sell;
}