/*
Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/
Problem: 1704. Determine if String Halves Are Alike
*/
static bool isVowel(char c){
    static char *v = "aeiouAEIOU";
    int v_len = strlen(v);
    int i;

    for (i = 0; i < v_len; i++){
        if (c == v[i]){
            return true;
        }
    }

    return false;
}

bool halvesAreAlike(char * s){
    int s_len = strlen(s);
    int i, j;
    int a, b;

    i = 0;
    j = s_len >> 1;
    a = b = 0;

    while (i < j && j < s_len){
        a = isVowel(s[i]) ? a + 1 : a;
        b = isVowel(s[j]) ? b + 1 : b;
        i++;
        j++;
    }

    return a == b;
}