/*
Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
Problem: 1561. Maximum Number of Coins You Can Get
*/

static int decrCmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int maxCoins(int* piles, int pilesSize) {
    int ans = 0, t, p = 1;
    
    /* Sort in descending order for convenience*/
    qsort(piles, pilesSize, sizeof(int), decrCmp);
    
    /* Alice picks the first largest pile   - 0, 3, 6, 9, ...
       I will pick the second largest pile  - 1, 4, 7, 10,...
       Bob will pick the third largest pile - 2, 5, 8, 11,...
       Repeat till there are no more piles */
    for (t = 0; t < (pilesSize / 3); t++){
        ans += piles[p];
        p += 2;
    }
    
    return ans;
}