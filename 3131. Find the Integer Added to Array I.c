/*
Problem: 3131. Find the Integer Added to Array I
Link: https://leetcode.com/problems/find-the-integer-added-to-array-i/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int min1 = nums1[0], min2 = nums2[0], i;
    
    for (i = 1; i < nums1Size; i++) {
        min1 = MINVAL(min1, nums1[i]);
        min2 = MINVAL(min2, nums2[i]);
    }
    
    return min2 - min1;
    
}