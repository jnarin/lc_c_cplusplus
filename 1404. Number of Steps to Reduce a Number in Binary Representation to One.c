/*
Problem: 1404. Number of Steps to Reduce a Number in Binary Representation to One
Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
*/

int numSteps(char* s) {
    int len, ans = 0, i;
    
    len = strlen(s) - 1;
    
    while (len >= 0 && s[len] == '0') {
        len--;
        ans++;
    }
    
    if (len == 0 && s[len] == '1') {
        return ans;
    }
    
    ans++;
    
    for (i = 0; i <= len; i++) {
        ans += s[i] == '1' ? 1 : 2;
    }
 
    return ans;
}