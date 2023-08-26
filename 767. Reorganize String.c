/*
 * Link: https://leetcode.com/problems/reorganize-string/
 * Problem: 767. Reorganize String
 * */

char * reorganizeString(char * s){
    int len = strlen(s), map[128] = {0}, i;
    char maxChar = 0, c;

    for (i = 0; i < len; i++){
        map[s[i]]++;
    }

    for (c = 'a'; c <= 'z'; c++){
        maxChar = map[c] > map[maxChar] ? c : maxChar;
    }

    if (map[maxChar] > (len + 1) / 2){
        s[0] = '\0';
        return s;
    }

    /* Put maxChar in even indices starting from
    0. Once maxChar is filled in, fill the remaining
    characters in odd indices */
    i = 0;
    while (i < len && map[maxChar] > 0){
        map[maxChar]--;
        s[i] = maxChar;
        i += 2;
        if (i >= len){
            i = 1;
            break;
        }
    }

    for (c = 'a'; c <= 'z'; c++){
        while (map[c] > 0 && i < len){
            map[c]--;
            s[i] = c;
            i += 2;
            i = i < len ? i : 1;
        }
    }

    return s;
}
