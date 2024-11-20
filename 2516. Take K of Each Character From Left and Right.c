/*
Problem: 2516. Take K of Each Character From Left and Right
Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
*/


#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int takeCharacters(char* s, int k) {
    int count[3] = {0}, i, len = strlen(s);

    for(i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (i = 0; i < 3; i++) {
        if (count[i] < k) {
            return -1;
        }
    }

    int max = 0, j = 0;
    
    for (i = 0; i < len; i++) {
        int c = s[i] - 'a';
        count[c]--;

        while (count[c] < k) {
            count[s[j] - 'a']++;
            j++;
        }

        max = MAXVAL(max, i - j + 1);

    }

    return len - max;    
}
