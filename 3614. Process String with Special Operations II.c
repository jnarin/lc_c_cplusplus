/*
Problem: 3614. Process String with Special Operations II
Link: https://leetcode.com/problems/process-string-with-special-operations-ii/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

char processStr(char* s, long long k) {
    long long m = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '*':
                m = MAXVAL((long)0, m - 1);
                break;
            case '#':
                m *= 2;
                break;
            case '%':
                break;
            default:
                m++;
        }
    }
    
    if (k >= m) {
        return '.';
    }

    for (int i = len - 1; ; i--) {
        switch (s[i]) {
            case '*':
                m += 1;
                break;
            case '#':
                m /= 2;
                if (k >= m) {
                    k -= m;
                }
                break;
            case '%':
                k = m - 1 - k;
                break;
            default:
                m--;
                if (k == m) {
                    return s[i];
                }
        }
    }

    return '.';
}
