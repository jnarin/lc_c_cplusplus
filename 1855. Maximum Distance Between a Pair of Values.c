/*
Problem: 1855. Maximum Distance Between a Pair of Values
Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j;
    int ans = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) {
            i++;
        } else {
            ans = MAXVAL(ans, j - i);
            j++;
        }
    }

    return ans;
}
