/*
 * Problem: 1915. Number of Wonderful Substrings
 * Link: https://leetcode.com/problems/number-of-wonderful-substrings/
 * */

#define MAX_COUNT   (1024)
long long wonderfulSubstrings(char * word){
    long long ans = 0;
    int prefix = 0, count[MAX_COUNT] = {0},
        i, len = strlen(word), j;

    count[0] = 1;

    for (i = 0; i < len; i++) {
        prefix ^= 1 << (word[i] - 'a');

        ans += count[prefix];

        for (j = 0; j < 10; j++) {
            ans += count[prefix ^ (1 << j)];
        }

        count[prefix]++;
    }

    return ans;
}

