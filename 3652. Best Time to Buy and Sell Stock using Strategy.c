/*
Problem: 3652. Best Time to Buy and Sell Stock using Strategy
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/
*/

typedef struct longLongPair_ {
    long long first, second;
} longlongPair;

long long maxProfit(int* prices, int pricesSize, int* strategy, int strategySize, int k) {
    long long ans = 0;
    longlongPair prefixSum[pricesSize], suffixSum[pricesSize];

    memset(prefixSum, 0, sizeof(prefixSum));
    memset(suffixSum, 0, sizeof(suffixSum));

    suffixSum[pricesSize - 1].first = prices[pricesSize- 1] * strategy[pricesSize - 1];
    suffixSum[pricesSize - 1].second = prices[pricesSize - 1];

    ans += prices[0] * strategy[0];

    prefixSum[0].first = ans;
    prefixSum[0].second = prices[0];

    int i;

    for (i = 1; i < pricesSize; i++) {
        ans += prices[i] * strategy[i];
        prefixSum[i].first = ans;
        prefixSum[i].second += prices[i] + prefixSum[i - 1].second;
    }

    for (i = pricesSize - 2; i >= 0; i--) {
        suffixSum[i].first = prices[i] * strategy[i] + suffixSum[i + 1].first;
        suffixSum[i].second = prices[i] + suffixSum[i + 1].second;
    }

    long long prefixRes, suffixRes, r, t;

    for (i = 0; i <= pricesSize - k; i++) {
        prefixRes = (i - 1 >= 0) ? prefixSum[i - 1].first : 0;
        suffixRes = (i + k < pricesSize) ? suffixSum[i + k].first : 0;
        r = prefixSum[i + k - 1].second - prefixSum[i + (k / 2) - 1].second;

        t = prefixRes + suffixRes + r;
        ans = t > ans ?  t : ans;
    }

    return ans;    
}
