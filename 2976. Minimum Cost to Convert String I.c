/*
Problem: 2976. Minimum Cost to Convert String I
Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    long dist[26][26], ans = 0;
    int i, j, k;
    int u, v;
    
    int sourceLen = strlen(source);
    
    for (i = 0; i < 26; i++){
        for (j = 0; j < 26; j++) {
            dist[i][j] = LONG_MAX;
        }
    }
    
    for (i = 0; i < costSize; i++) {
        u = original[i] - 'a';
        v = changed[i] - 'a';
        dist[u][v] = MINVAL(dist[u][v], cost[i]);
    }
    
    for (k = 0; k < 26; k++) {
        for (i = 0; i < 26; i++) {
            if (dist[i][k] < LONG_MAX) {
                for (j = 0; j < 26; j++) {
                    if (dist[k][j] < LONG_MAX) {
                        dist[i][j] = MINVAL(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    
    for (i = 0; i < sourceLen; i++) {
        if (source[i] == target[i]) {
            continue;
        }
        
        u = source[i] - 'a';
        v = target[i] - 'a';
        
        if (dist[u][v] == LONG_MAX) {
            return -1;
        }
        
        ans += dist[u][v];
    }
    
    return ans;
}
