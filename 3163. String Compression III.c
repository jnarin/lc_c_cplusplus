/*
Problem: 3163. String Compression III
Link: https://leetcode.com/problems/string-compression-iii
*/

#define MAX_OUT_SIZE ((2 * 100000 )* 2 + 1)

char* compressedString(char* word) {
    char *ans = calloc(MAX_OUT_SIZE, sizeof(char));
    int i, j, ansIdx, len = strlen(word), count;
    
    i = j = ansIdx = 0;

    while (i < len){
        count = 0;

        while (j < len && word[i] == word[j] && count < 9) {
            j++;
            count++;
        }

        ans[ansIdx++] = count + '0';
        ans[ansIdx++] = word[i];
        
        i = j;
    }

    ans[ansIdx] = '\0';

    return ans;
}
