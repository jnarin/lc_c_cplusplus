/*
Problem: 2226. Maximum Candies Allocated to K Children
Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
*/

static long long arraySum(int *array, int arraySize) {
    long long ans = 0
    int i;
    
    for (i = 0; i  < arraySize; i++) {
        ans += array[i];
    }

    return ans;
}

static long long numChildren(int *candies, int candiesSize, int m) {
    long long ans = 0;
    int i;

    for (i = 0; i < candiesSize; i++) {
        ans += candies[i] / m;
    }

    return ans;
}

int maximumCandies(int* candies, int candiesSize, long long k) {
    long long l = 1, r = arraySum(candies, candiesSize) / k, m;

    while (l < r) {
        m = (l + r) / 2;

        if (numChildren(candies, candiesSize, m) < k) {
            r = m;
        } else {
            l = m + 1;
        }

    }

    return numChildren(candies, candiesSize, l) >= k ? l : l - 1;   
}
