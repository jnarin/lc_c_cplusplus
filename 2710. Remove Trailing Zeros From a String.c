/*
Link: https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
Problem: 2710. Remove Trailing Zeros From a String
*/
char * removeTrailingZeros(char * num){
    int len = strlen(num), i;
    
    for (i = len - 1; i >= 0 && num[i] == '0'; i--){
        ;
    }
    
    if (i >= 0 && i < len){
        num[i + 1] = '\0';
    }
    
    return num;
}