/*
 * Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * Problem: 557. Reverse Words in a String III
 * */

#define SWAP(a, b)  \
({  __typeof__(a) t = (a);\
    t = a;\
    a = b;\
    b = t;  })

static void reverseRange(char *s, int l, int r){
    while (l < r){
        SWAP(s[l], s[r]);
        l++;
        r--;
    }
}

char * reverseWords(char * s){
    int l = 0, r = l + 1;

    while (s[r] != '\0'){
        while (s[r] != '\0' && s[r] != ' '){
            r++;
        }

        r--;

        reverseRange(s, l, r);

        r++;

        if (s[r] == '\0'){
            break;
        }

        l = r + 1;
        r = l + 1;
    }

    return s;
}
