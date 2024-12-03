/*
Problem: 2109. Adding Spaces to a String
Link: https://leetcode.com/problems/adding-spaces-to-a-string/
*/

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int sLen = strlen(s), i, j, k;
    char *ans = calloc(sLen + spacesSize + 1, sizeof(char));
    
    i = j = k = 0;
    while (i < sLen) {
        if (k < spacesSize && i == spaces[k]) {
            ans[j++] = ' ';
            k++;
        } else {
            ans[j++] = s[i++];
        }
    }
    
    return ans;
}
