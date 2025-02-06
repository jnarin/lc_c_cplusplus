/*
Problem: 1726. Tuple with Same Product
Link: https://leetcode.com/problems/tuple-with-same-product/description
*/
static int getMax(int *nums, int numsSize) {
    int i, ans = INT_MIN;

    for (i = 0; i < numsSize; i++) {
        ans = nums[i] > ans ? nums[i] : ans;
    }

    return ans;
}

int tupleSameProduct(int* nums, int numsSize) {
    int *map, i, j, ans = 0;

    int m = getMax(nums, numsSize);
    map = calloc(m * m + 1, sizeof(int));

    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            ans += map[nums[i] * nums[j]]++ * 8;
        }
    }

    free(map);
    
    return ans;
}
