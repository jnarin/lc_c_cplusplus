/*
 * Link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
 * Problem: 1793. Maximum Score of a Good Subarray
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })


int maximumScore(int* nums, int numsSize, int k){
    int ans, m, i, j;
    ans = m = nums[k];
    i = j = k;
    
    while (i > 0 || j < numsSize - 1){
        if (i == 0){
            j++;
        } else if (j == numsSize - 1){
            i--;
        } else if (nums[i - 1] < nums[j + 1]){
            j++;
        } else {
            i--;
        }
        
        m = MINVAL(m, MINVAL(nums[i], nums[j]));
        ans = MAXVAL(ans, m * (j - i + 1));
    }
    
    return ans;    
}
