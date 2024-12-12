/*
Problem: 2558. Take Gifts From the Richest Pile
Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
*/

static int findMaxIdx(int *nums, int numsSize) {
    int max = INT_MIN, i, maxIdx = -1;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            maxIdx = i;
        }
    }
    
    return maxIdx;
}

static long long sum(int *nums, int numsSize) {
    long long sum = 0;
    int i;
    
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    return sum;
}

long long pickGifts(int* gifts, int giftsSize, int k) {
    int i = 0, maxIdx;
    
    while (k) {
        maxIdx = findMaxIdx(gifts, giftsSize);
        gifts[maxIdx] = sqrt(gifts[maxIdx]);
        
        k--;
    }
    
    return sum(gifts, giftsSize);
}
