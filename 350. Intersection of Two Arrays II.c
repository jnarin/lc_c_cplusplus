/*
Problem: 350. Intersection of Two Arrays II
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_VAL (1001)

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int map[MAX_VAL] = {0}, i;
    int tmpSize = nums1Size > nums2Size ? nums1Size : nums2Size;
    int tmp[tmpSize], idx = 0;
    
    memset(tmp, 0, sizeof(tmp));
    
    for (i = 0; i < nums1Size; i++) {
        map[nums1[i]]++;
    }
    
    for (i = 0; i < nums2Size; i++) {
        if (map[nums2[i]] > 0) {
            tmp[idx++] = nums2[i];
            map[nums2[i]]--;
        }
    }
    
    int *ans = calloc(idx, sizeof(int));
    *returnSize = idx;
    
    memcpy(ans, tmp, idx * sizeof(int));
    
    return ans;    
}