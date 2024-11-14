/*
Problem: 2064. Minimized Maximum of Products Distributed to Any Store
Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
*/

int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    int left = 1, right = 1e5, mid, i;
    long long sum;

    while (left < right) {
        mid = (left + right) / 2;
        sum = 0;

        for (i = 0; i < quantitiesSize; i++) {
            sum += (quantities[i] + mid - 1) / mid;
        }

        if (sum > n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
