/*
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
Problem: 4. Median of Two Sorted Arrays
*/
#define MIDVAL(a, b) ((a) & (b)) + (((a) ^ (b)) >> 1)

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b; })

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b; })

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int l = 0, r = nums1Size;
    int p1, p2, l1, r1, l2, r2;
    double ans = INT_MIN;
    
    while (l <= r){
        p1 = MIDVAL(l, r);
        p2 = ((nums1Size + nums2Size + 1) >> 1) - p1;
        l1 = p1 == 0 ? INT_MIN : nums1[p1 - 1];
        l2 = p2 == 0 ? INT_MIN : nums2[p2 - 1];
        r1 = p1 == nums1Size ? INT_MAX : nums1[p1];
        r2 = p2 == nums2Size ? INT_MAX : nums2[p2];
        
        if (l1 <= r2 && l2 <= r1){
            ans = ((nums1Size + nums2Size) & 1) == 0 
                ? (double)(MAXVAL(l1, l2) + MINVAL(r1, r2))/(double)2 
                : (double)MAXVAL(l1, l2);
            break;
        } else if (l1 > r2){
            r = p1 - 1;
        } else {
            l = p1 + 1;
        }
    }
    
    return ans;
}