/*
Problem: 2300. Successful Pairs of Spells and Potions
Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/

#define MID(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static int findIndex(int s, int *potions, int potionsSize, long long success) {
    int l = 0, r = potionsSize - 1, m;
    while (l <= r){
        m = MID(l, r);
        if ((long long)s * potions[m] >= success){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return l;    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int *ans = calloc(spellsSize, sizeof(int)), i, idx = 0;
    *returnSize = spellsSize;

    qsort(potions, potionsSize, sizeof(int), incrCmp);

    for (i = 0; i < spellsSize; i++) {
        ans[idx++] = potionsSize - findIndex(spells[i], potions, potionsSize, success);
    }
    
    return ans;
}
