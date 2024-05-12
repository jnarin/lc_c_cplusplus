/*
 * Problem: 506. Relative Ranks
 * Link: https://leetcode.com/problems/relative-ranks/
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STR_LEN (13)
#define MAX_NUM     (1000001)

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int sortedScore[scoreSize];

    memcpy(sortedScore, score, scoreSize * sizeof(int));

    qsort(sortedScore, scoreSize, sizeof(int), decrCmp);

    char map[MAX_NUM][MAX_STR_LEN + 1] = {0}, **ans;
    int i;

    ans = calloc(scoreSize, sizeof(char *));
    for (i = 0; i < scoreSize; i++) {
        ans[i] = calloc(MAX_STR_LEN + 1, sizeof(char));
    }

    for (i = 1; i <= scoreSize; i++) {
        if (i > 3) {
            snprintf(map[sortedScore[i - 1]], MAX_STR_LEN, "%d", i);
            continue;
        }

        switch (i) {
            case 1:
                snprintf(map[sortedScore[i - 1]], MAX_STR_LEN, "Gold Medal");
                break;

            case 2:
                snprintf(map[sortedScore[i - 1]], MAX_STR_LEN, "Silver Medal");
                break;

            case 3:
                snprintf(map[sortedScore[i - 1]], MAX_STR_LEN, "Bronze Medal");
                break;

            default:
                assert(0);
        }
    }

    for (i = 0; i < scoreSize; i++) {
        strncpy(ans[i], map[score[i]], MAX_STR_LEN);
    }

    *returnSize = scoreSize;

    return ans;
}
