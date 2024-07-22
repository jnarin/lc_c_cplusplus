/*
Problem: 2418. Sort the People
Link: https://leetcode.com/problems/sort-the-people/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct heightIdx {
    int height;
    int idx;
};

static int decrCmp(const void* a, const void* b) {
    struct heightIdx* p1 = (struct heightIdx*)a;
    struct heightIdx* p2 = (struct heightIdx*)b;
    
    return p1->height != p2->height ? p2->height - p1->height : p1->idx - p2->idx;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    struct heightIdx people[namesSize];
    int i;
    char **ans = calloc(namesSize, sizeof(char *));
    
    for (i = 0; i < namesSize; i++) {
        people[i].height = heights[i];
        people[i].idx = i;
    }

    qsort(people, namesSize, sizeof(struct heightIdx), decrCmp);

    *returnSize = namesSize;

    for (i = 0; i < namesSize; i++) {
        ans[i] = calloc(strlen(names[people[i].idx]) + 1, sizeof(char));
        strcpy(ans[i], names[people[i].idx]);
    }
    
    return ans;    
}
