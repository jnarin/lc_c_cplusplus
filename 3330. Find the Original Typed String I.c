/*
Problem: 3330. Find the Original Typed String I
Link: https://leetcode.com/problems/find-the-original-typed-string-i/
*/

int possibleStringCount(char* word) {
    int ans = 1;

    word++;
    while (*word) {
        ans += (*word == *(word - 1));
        word++;
    }

    return ans;    
}
