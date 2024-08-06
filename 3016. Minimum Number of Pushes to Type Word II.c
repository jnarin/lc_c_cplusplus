/*
Problem: 3016. Minimum Number of Pushes to Type Word II
Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
*/

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minimumPushes(char* word) {
    int freq[26] = {0}, i, ans = 0,
        len = strlen(word);
    
    for (i = 0; i < len; i++) {
        freq[word[i] - 'a']++;
    }
    
    qsort(freq, 26, sizeof(int), decrCmp);
    
    for (i = 0; i < 26; i++) {
        ans += freq[i] * (i / 8 + 1);
    }
    
    return ans;
}
