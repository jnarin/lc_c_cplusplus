/*
Problem: 2465. Number of Distinct Averages
Link: https://leetcode.com/problems/number-of-distinct-averages/
*/

static int incrCmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int distinctAverages(int* nums, int numsSize) {
    int map[201] = {0}, i, ans = 0;
    
    qsort(nums, numsSize, sizeof(int), incrCmp);
    for (i = 0; i < numsSize / 2; i++) {
        map[nums[i] + nums[numsSize - 1 - i]] = 1;
    }

    for (i = 0; i < 201; i++) {
        ans += map[i] ? 1 : 0;
    }
    
    return ans;
}
