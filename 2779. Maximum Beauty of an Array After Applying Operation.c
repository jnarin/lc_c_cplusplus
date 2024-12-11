/*
Problem: 2779. Maximum Beauty of an Array After Applying Operation
Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
*/


#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int incrCmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), incrCmp);

    int ans = 0, l = 0, r = 0;

    while (r < numsSize) {
        while (nums[r] - nums[l] > (k << 1)) {
            l++;
        }

        ans = MAXVAL(ans, r - l + 1);
        
        r++;
    }

    return ans;
    
}
