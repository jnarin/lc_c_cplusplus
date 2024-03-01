/*
Link: https://leetcode.com/problems/maximum-odd-binary-number/
Problem: 2864. Maximum Odd Binary Number
*/
char* maximumOddBinaryNumber(char* s){
    int len = strlen(s), i, oneCount = 0;
    
    for (i = 0; i < len; i++) {
        oneCount = s[i] == '1' ? oneCount + 1 : oneCount;
    }
    
    char *ans = calloc(len + 1, sizeof(char));
    memset(ans, '0', len);
    
    ans[len - 1] = '1';
    oneCount--;
    i = 0;
    
    while (oneCount-- && i < len) {
        ans[i++] = '1';
    } 
    
    return ans;
}