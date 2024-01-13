/*
 * Link: https://leetcode.com/problems/minimum-common-value/
 * Problem: 2540. Minimum Common Value
 * */

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j;
    i = j = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        }

        if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }

    return -1;
}

