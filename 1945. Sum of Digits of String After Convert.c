/*
Problem: 1945. Sum of Digits of String After Convert
Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
*/

static int convertStoI(char *s) {
    int ans = 0, len = strlen(s), i;
    char c;
    
    for (i = 0; i < len; i++) {
        c = s[i] - 'a' + 1;
        ans += c < 10 ? c : (c % 10 + c / 10);
    }
    
    return ans;
}

static int getDigitSum(int n) {
    int sum = 0;
    
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    
    return sum;
}

int getLucky(char* s, int k) {
    int ans = convertStoI(s), i;
    
    for (i = 1; i < k; i++) {
        ans = getDigitSum(ans);
    }
    
    return ans;
}
