/*
Problem: 521. Longest Uncommon Subsequence I
Link: https://leetcode.com/problems/longest-uncommon-subsequence-i/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int findLUSlength(char* a, char* b) {
    return strcmp(a, b) == 0 ? -1 : MAXVAL(strlen(a), strlen(b));
}
