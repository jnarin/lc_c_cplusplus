/*
Problem: 2894. Divisible and Non-divisible Sums Difference
Link: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
*/

int differenceOfSums(int n, int m) {
    int i, nums1 = 0, nums2 = 0;

    for (i = 1; i <= n; i++) {
        if (i % m) {
            nums1 += i;
        } else {
            nums2 += i;
        }
    }
    
    return nums1 - nums2;
}
