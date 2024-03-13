/*
Link: https://leetcode.com/problems/custom-sort-string/
Problem: 791. Custom Sort String
*/

char* customSortString(char* order, char* s) {
    int orderLen = strlen(order), sLen = strlen(s), i, map[26] = {0}, idx = 0;
    char *ans = calloc(sLen + 1, sizeof(char));
    
    for (i = 0; i < sLen; i++) {
        map[s[i] - 'a']++;
    }
    
    for (i = 0; i < orderLen; i++) {
        while (map[order[i] - 'a']-- > 0) {
            ans[idx++] = order[i];
        }
    }
    
    for (i = 0; i < 26; i++) {
        while(map[i]-- > 0) {
            ans[idx++] = i  + 'a';
        }
    }
    
    return ans;
}