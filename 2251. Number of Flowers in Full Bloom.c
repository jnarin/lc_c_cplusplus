/*
Link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/
Problem: 2251. Number of Flowers in Full Bloom
*/
#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

static int upperBound(int *nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, m;
    
    while (l < r){
        m = MIDVAL(l, r);
        
        if (target >= nums[m]){
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    if (l < numsSize && nums[l] <= target){
        l++;
    }
    
    return l;
}

static int lowerBound(int *nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, m;
    
    while (l < r){
        m = MIDVAL(l, r);
        
        if (target <= nums[m]){
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    if (l < numsSize && nums[l] < target){
        l++;
    }
    
    return l;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize, int* people, int peopleSize, int* returnSize){
    int *ans = calloc(peopleSize, sizeof(int));
    *returnSize = peopleSize;
    
    int starts[flowersSize], ends[flowersSize], s, e, i;
    
    for (i = 0; i < flowersSize; i++){
        starts[i] = flowers[i][0];
        ends[i] = flowers[i][1];
    }
    
    qsort(starts, flowersSize, sizeof(int), incrCmp);
    qsort(ends, flowersSize, sizeof(int), incrCmp);
    
    for (i = 0; i < peopleSize; i++){
        s = upperBound(starts, flowersSize, people[i]);
        e = lowerBound(ends, flowersSize, people[i]);
        ans[i] = s- e;
    }
    
    return ans;
}
