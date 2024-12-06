/*
Problem: 2554. Maximum Number of Integers to Choose From a Range I
Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    qsort(banned, bannedSize, sizeof(int), incrCmp);
    
    int i, j, ans, sum;
    ans = sum = 0;
    
    j = 0;
    for (i = 1; i <= n; i++) {
        if (sum + i > maxSum) {
            break;
        }
        
        if (j < bannedSize && i == banned[j]) {
            while (j < bannedSize && i == banned[j]) {
                j++;
            }
        } else {
            sum += i;
            ans++;
        }
    }  

    return ans;
}
