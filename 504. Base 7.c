/*
Problem: 504. Base 7
Link: https://leetcode.com/problems/base-7/
*/

static void reverse(char *s, int sLen) {
    int i;
    char temp;
    
    for(i = 0; i < sLen / 2; i++) {
        temp = s[i];
        s[i] = s[sLen - i - 1];
        s[sLen - i - 1] = temp;
    }

    return;
}

char* convertToBase7(int num) {
    char *ans = calloc(20, sizeof(char));
    int n, i = 0;

    if(num == 0) {
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }
 
    n = abs(num);

    while(n > 0) {
        ans[i++] = n % 7 + '0';
        n /= 7;
    }

    if(num < 0) {
        ans[i++] = '-';
    }

    ans[i] = '\0';

    reverse(ans, i);

    return ans;
}
