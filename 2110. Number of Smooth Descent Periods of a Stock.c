/*
Problem: 2110. Number of Smooth Descent Periods of a Stock
Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
*/

long long getDescentPeriods(int* prices, int pricesSize) {
    long long ans = 1, length = 1;
    int i;

    for (i = 1; i < pricesSize; i++) {
        length = (prices[i] == prices[i - 1] - 1) ? length + 1 : 1;
        ans += length;
    }

    return ans;
}
