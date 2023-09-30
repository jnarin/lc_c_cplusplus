/*
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
 * Problem: 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
 * */
#define MINVAL(a, b)  \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int gcd(int a, int b){
    int ans = MINVAL(a, b);
    while (ans > 0) {
        if (a % ans == 0 && b % ans == 0) {
            break;
        }

        ans--;
    }

    return ans;
}

int minOperations(int* nums, int numsSize){
    int i, j, numOnes = 0;

    for (i = 0; i < numsSize; i++){
        numOnes = (nums[i] == 1) ? numOnes + 1 : numOnes;
    }

    if (numOnes){
        return numsSize - numOnes;
    }

    int ans = INT_MAX, gcdval;

    for (i = 0; i < numsSize; i++){
        gcdval = nums[i];
        for (j = i + 1; j < numsSize; j++){
            gcdval = gcd(gcdval, nums[j]);
            if (gcdval == 1){
                ans = MINVAL(ans, j - i);
                break;
            }
        }
    }

    return ans == INT_MAX ? -1 : ans + numsSize - 1;
}
