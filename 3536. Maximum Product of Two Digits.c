/*
Problem: 3536. Maximum Product of Two Digits
Link: https://leetcode.com/problems/maximum-product-of-two-digits/
*/

#define MAXDIGITS (10)

static int incrCmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int maxProduct(int n) {
    char num[MAXDIGITS + 1];
    num[MAXDIGITS] = '\0';

    snprintf(num, MAXDIGITS, "%d", n);

    int len = strlen(num);
    qsort(num, len, sizeof(char), incrCmp);
    
    return (num[len - 1] - '0') * (num[len - 2] - '0');
}
