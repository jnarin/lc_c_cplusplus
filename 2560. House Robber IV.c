/*
Problem: 2560. House Robber IV
Link: https://leetcode.com/problems/house-robber-iv/
*/
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int minVal(int *nums, int numsSize) {
    int ans = INT_MAX, i;

    for (i = 0; i < numsSize; i++) {
        ans = MINVAL(ans, nums[i]);
    }

    return ans;
}

static int maxVal(int *nums, int numsSize) {
    int ans = INT_MIN, i;

    for (i = 0; i < numsSize; i++) {
        ans = MAXVAL(ans, nums[i]);
    }

    return ans;
}

static int numStolenHouses(int *nums, int numsSize, int c) {
    int ans = 0, i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] <= c) {
            ans++;
            i++;
        }
    }

    return ans;
}

int minCapability(int* nums, int numsSize, int k){
    int l = minVal(nums, numsSize), r = maxVal(nums, numsSize), m;

    while (l < r) {
        m = (l + r) / 2;

        if (numStolenHouses(nums, numsSize, m) >= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;
}
