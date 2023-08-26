/*
 * Link: https://leetcode.com/problems/repeated-substring-pattern/
 * Problem: 459. Repeated Substring Pattern
 * */

bool repeatedSubstringPattern(char * s){
    int len = strlen(s), newLen = (2 * len) + 1;
    char t[newLen];

    t[newLen - 1] = '\0';
    strncpy(&t[0], s, len);
    strncpy(&t[len], s, len);

    char *p = strstr(&t[1], s);

    return (p - t != len) ? true : false;
}
