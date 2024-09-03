/*
Problem: 1528. Shuffle String
Link: https://leetcode.com/problems/shuffle-string/
*/

char* restoreString(char* s, int* indices, int indicesSize) {
    int i;
    char *ans = calloc(indicesSize + 1, sizeof(char));
    
    for (i = 0; i < indicesSize; i++) {
        ans[indices[i]] = s[i];
    }
    
    return ans;
}
