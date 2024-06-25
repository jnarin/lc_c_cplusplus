/*
Problem: 1442. Count Triplets That Can Form Two Arrays of Equal XOR
Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/

int countTriplets(int* arr, int arrSize){
    int ans = 0, start, end, mid, xorA, xorB;
    
    for (start = 0; start < arrSize; start++) {
        xorA = 0;
        
        for (mid = start + 1; mid < arrSize; mid++) {
            xorA ^= arr[mid - 1];
            
            xorB = 0;
            
            for (end = mid; end < arrSize; end++) {
                xorB ^= arr[end];
                
                ans += xorA == xorB ? 1 : 0;
            }
        }
    }

    return ans;
}