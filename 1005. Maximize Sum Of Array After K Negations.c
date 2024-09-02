/*
Problem: 1005. Maximize Sum Of Array After K Negations
Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static int arraySum(int *arr, int size) {
    int ans = 0, i;
    
    for (i = 0; i < size; i++) {
        ans += arr[i];
    }
    
    return ans;
}


static int arrayMin(int *arr, int size) {
    int ans = INT_MAX, i;
    
    for (i = 0; i < size; i++) {
        ans = arr[i] < ans ? arr[i] : ans;
    }
    
    return ans;
}

int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    int i;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0 || k == 0) {
            break;
        }
        
        nums[i] *= -1;
        k--;
    }
    
    return arraySum(nums, numsSize) - ((k & 1) << 1) * arrayMin(nums, numsSize);
}
