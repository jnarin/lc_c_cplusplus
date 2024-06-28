/*
Problem: 2285. Maximum Total Importance of Roads
Link: https://leetcode.com/problems/maximum-total-importance-of-roads/
*/

static int incrCmp(const void *a, const void *b) {
    return *(long long *)a - *(long long *)b;
}

long long maximumImportance(int n, int** roads, int roadsSize, int* roadsColSize) {
    long long degree[n], ans = 0;
    int i;
    
    memset(degree, 0, sizeof(degree));
    
    for (i = 0; i < roadsSize; i++) {
        degree[roads[i][0]]++;
        degree[roads[i][1]]++;
    }
    
    qsort(degree, n, sizeof(long long), incrCmp);
    
    for (i = 0; i < n; i++) {
        ans += ((i + 1) * degree[i]);
    }
    
    return ans;
}