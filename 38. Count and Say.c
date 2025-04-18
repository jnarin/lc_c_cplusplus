/*
Problem: 38. Count and Say
Link: https://leetcode.com/problems/count-and-say/
*/

char * countAndSay(int n){
    if (n == 1) {
        char *base = calloc(2, sizeof(char));
        base[0] = '1';

        return base;
    }
    
    char *prev = countAndSay(n - 1);
    int len = strlen(prev);
    char *result = calloc(2 * len + 1, sizeof(char));
    int i, j = 0, count = 1;

    for (i = 1; i <= len; i++) {
        if (prev[i] == prev[i - 1]) {
            count++;
        } else {
            j += sprintf(result + j, "%d%c", count, prev[i - 1]);
            count = 1;
        }
    }

    result[j] = '\0';
    free(prev);

    return result;
}
