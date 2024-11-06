/*
Problem: 3011. Find if Array Can Be Sorted
Link: https://leetcode.com/problems/find-if-array-can-be-sorted/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int countSetBits(int n) {
    int c;

    for (c = 0; n; c++) {
        n &= n - 1;
    }

    return c;
}

bool canSortArray(int* nums, int numsSize) {
    int pSetBits, pMax, cMax, cMin, i, bitCount;

    pSetBits = 0;
    pMax = cMax = INT_MIN;
    cMin = INT_MAX;

    for (i = 0; i < numsSize; i++) {
        bitCount = countSetBits(nums[i]);
        
        if (bitCount != pSetBits) {
            if (pMax > cMin) {
                return false;
            }

            pMax = cMax;
            cMin = cMax = nums[i];
            pSetBits = bitCount;
        } else {
            cMax = MAXVAL(cMax, nums[i]);
            cMin = MINVAL(cMin, nums[i]);
        }
    }

    return pMax <= cMin;
}
