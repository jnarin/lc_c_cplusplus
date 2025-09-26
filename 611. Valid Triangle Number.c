/*
Problem: 611. Valid Triangle Number
Link: https://leetcode.com/problems/valid-triangle-number/
*/

static int incrCmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    int ans = 0;
    if (numsSize < 3){
        return ans;
    }

    // Sort the array
    qsort(nums, numsSize, sizeof(int), incrCmp);

    for (int k = numsSize - 1; k > 1; k--) {
        int i = 0, j = k - 1;

        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }

    return ans;
}
