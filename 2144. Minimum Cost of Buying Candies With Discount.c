/*
Problem: 2144. Minimum Cost of Buying Candies With Discount
Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
*/

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), decrCmp);
    
    int ans = 0, i;

    for (i = 0; i < costSize; i++) {
        if ((i % 3) == 2) continue;
        ans += cost[i];
    }

    return ans;
}
