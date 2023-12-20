/*
Link: https://leetcode.com/problems/buy-two-chocolates/
Problem: 2706. Buy Two Chocolates
*/

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int buyChoco(int* prices, int pricesSize, int money){
    qsort(prices, pricesSize, sizeof(int), incrCmp);
    
    int t = prices[0] + prices[1];
    
    
    return t <= money ? money - t : money;
}