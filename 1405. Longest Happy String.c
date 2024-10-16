/*
Problem: 1405. Longest Happy String
Link: https://leetcode.com/problems/longest-happy-string/
*/

char* longestDiverseString(int a, int b, int c) {
    int maxLen = a + b + c;
    char *ans = calloc(maxLen + 1, sizeof(char));
    
    ans[maxLen] = '\0';
    
    int idx = 0;
    
    int count[3];
    
    count[0] = a > 0 ? a : 0;
    count[1] = b > 0 ? b : 0;
    count[2] = c > 0 ? c : 0;

    while (count[0] || count[1] || count[2]) {
        int max = 0, maxIdx = -1, i;
        for (i = 0; i < 3; i++) {
            if (count[i] > max && (idx < 2 || ans[idx - 1] != 'a' + i || ans[idx - 2] != 'a' + i)) {
                max = count[i];
                maxIdx = i;
            }
        }

        if (maxIdx == -1) {
            break;
        }

        ans[idx++] = 'a' + maxIdx;
        count[maxIdx]--;
    }
    
    return ans;
}
