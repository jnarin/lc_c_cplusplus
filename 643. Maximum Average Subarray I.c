/*
 * Link: https://leetcode.com/problems/maximum-average-subarray-i/
 * Problem: 643. Maximum Average Subarray I
 * */
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

double findMaxAverage(int* nums, int numsSize, int k){
    double ans, sum = 0;
    int i, j;

    ans = INT_MIN;

    i = j = 0;
    while (j < numsSize && j < k){
        sum += nums[j++];
    }


    while (j < numsSize){
        ans = MAXVAL(ans, sum / k);

        sum -= nums[i++];
        sum += nums[j++];
    }

    ans = MAXVAL(ans, sum / k);

    return ans;
}

