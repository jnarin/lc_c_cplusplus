/*
 * Link: https://leetcode.com/problems/assign-cookies/
 * Problem: 455. Assign Cookies
 * */

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), incrCmp);
    qsort(s, sSize, sizeof(int), incrCmp);

    int contentChildren = 0, cookieIndex = 0;

    while (cookieIndex < sSize && contentChildren < gSize) {
        if (s[cookieIndex] >= g[contentChildren]) {
            contentChildren++;
        }

        cookieIndex++;
    }

    return contentChildren;
}

