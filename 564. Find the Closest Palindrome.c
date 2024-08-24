/*
Problem: 564. Find the Closest Palindrome
Link: https://leetcode.com/problems/find-the-closest-palindrome/
*/

#define MAXLEN  (20)

static long long convert(long long num) {
    char s[MAXLEN + 1];

    s[MAXLEN] = '\0';
    snprintf(s, MAXLEN, "%lld", num);
    
    int n = strlen(s);
    int l = (n - 1) / 2, r = n / 2;

    while (l >= 0) {
        s[r++] = s[l--];
    }
    
    return atoll(s);
}

static long long nextPalindrome(long long num) {
    long long left = num, right = 1e18, mid, p, ans = INT_MIN;

    while (left <= right) {
        mid = (right - left) / 2 + left;
        p = convert(mid);
        
        if (p > num) {
            ans = p;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return ans;
}

static long long prevPalindrome(long long num) {
    long long left = 0, right = num, mid, p, ans = INT_MIN;
    
    while (left <= right) {
        mid = (right - left) / 2 + left;
        p = convert(mid);
        
        if (p < num) {
            ans = p;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}

char* nearestPalindromic(char* n) {
    long long num = atoll(n), small = prevPalindrome(num), big = nextPalindrome(num);
    char *res = calloc(MAXLEN + 1, sizeof(char));
    
    printf("%lld, %lld\n", small, big);

    if (num - small <= big - num) {
        snprintf(res, MAXLEN, "%lld", small);
    } else {
        snprintf(res, MAXLEN, "%lld", big);
    }

    return res;
}
