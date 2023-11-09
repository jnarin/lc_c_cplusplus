/*
Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/
Problem: 1759. Count Number of Homogenous Substrings
*/
#define MOD (int)(1e9 + 7)

int countHomogenous(char * s){
    int len = strlen(s);
    int i, ans, count;
    char c = 0;
    
    ans = count  = 0;
    
    for (i = 0; i < len; i++){
        if (c == s[i]){
            count++;
        } else {
            count = 1;
        }
        
        c = s[i];
        ans = (ans + count) % MOD;
    }
    
    return ans;

}