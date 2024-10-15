/*
Problem: 2938. Separate Black and White Balls
Link: https://leetcode.com/problems/separate-black-and-white-balls/
*/

long long minimumSteps(char* s) {
    long long ans, ones;
    ans = ones = 0;
    
    while (*s) {
        if (*s == '1') {
            ones++;
        } else {
            ans += ones;
        }
        
        s++;
    }
    
    return ans;
}
