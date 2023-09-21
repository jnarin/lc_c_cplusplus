/*
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
Problem: 4. Median of Two Sorted Arrays
Time complexity of this solution is O(m + n). 
The ask is for a solution with time complexity O(log(m + n))
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int t[nums1Size + nums2Size], tSize = nums1Size + nums2Size, tIdx = 0;
    int i, j;
    
    /* Merge the two arrays into a sorted array*/
    i = j = 0;
    while (i < nums1Size && j < nums2Size){
        if (nums1[i] < nums2[j]){
            t[tIdx] = nums1[i++];
        } else {
            t[tIdx] = nums2[j++];
        }
        
        tIdx++;
    }
    
    while (i < nums1Size){
        t[tIdx++] = nums1[i++];
    }
    
    while (j < nums2Size){
        t[tIdx++] = nums2[j++];
    }
    
    double ans;
    
    /* Get the median from the sorted array */
    if (tSize & 1){
        ans = t[tSize >> 1];
    } else {
        int a = t[tSize >> 1], b = t[(tSize >> 1) - 1];
        ans = (double)(a + b)/(double)2;
    }
    
    return ans;
}