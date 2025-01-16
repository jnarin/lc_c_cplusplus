/*
Problem: 2425. Bitwise XOR of All Pairings
Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/
*/

static int arrayXor(int *array, int arraySize) {
    int ans = 0, i;

    for (i = 0; i < arraySize; i++) {
        ans ^= array[i];
    }

    return ans;
}

int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int xor1 = arrayXor(nums1, nums1Size), xor2 = arrayXor(nums2, nums2Size);

    return ((nums1Size & 1) * xor2) ^ ((nums2Size & 1) * xor1);

    
}
