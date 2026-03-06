/*
Problem: 1784. Check if Binary String Has at Most One Segment of Ones
Link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
*/
bool checkOnesSegment(char* s) {
    while (*s && *s == '1') {
        s++;
    }

    while (*s) {
        if (*s == '1') {
            return false;
        }

        s++;
    }
    
    return true;
}
