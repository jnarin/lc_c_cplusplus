/*
Problem: 2191. Sort the Jumbled Numbers.c
Link: https://leetcode.com/problems/sort-the-jumbled-numbers/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct mapNum {
    int val;
    int idx;
};

static int incrCmp(const void *a, const void *b) {
    return ((struct mapNum *)a)->val - ((struct mapNum *)b)->val;
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(sizeof(int) * numsSize), i;
    struct mapNum m[numsSize];
    
    *returnSize = numsSize;    

    // Replace numbers in nums with mapping
    for (i = 0; i < numsSize; i++)  {
        int n = nums[i];
        int digit;
        int modNum = 0;
        int multiplier = 1;

        // Handle the case where n is 0 explicitly
        if (n == 0) {
            modNum = mapping[0];
        } else {
            // Calculate the number of digits to correctly map numbers with leading zeros after mapping
            int temp = n;
            while (temp) {
                multiplier *= 10;
                temp /= 10;
            }
            multiplier /= 10;

            while (n || multiplier) {
                digit = n / multiplier;
                modNum = modNum * 10 + mapping[digit];
                n %= multiplier;
                multiplier /= 10;
            }
        }

        m[i].val = modNum;
        m[i].idx = i;
    }

    qsort(m, numsSize, sizeof(struct mapNum), incrCmp);

    for (i = 0; i < numsSize; i++) {
        ans[i] = nums[m[i].idx];
    }

    return ans;    
}
