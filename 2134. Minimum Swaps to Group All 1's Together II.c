/*
Problem: 2134. Minimum Swaps to Group All 1's Together II
Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
*/

int minSwaps(int* nums, int numsSize) {
    int i, totalOnes = 0, oneCount = 0, maxOnes = 0;
    
    for (i = 0; i < numsSize; i++) {
        totalOnes += nums[i] ? 1 : 0;
    }
    
    for (i = 0; i < (numsSize * 2); i++) {
        if (i >= totalOnes && nums[(i - totalOnes) % numsSize]) {
            oneCount--;
        }
        
        if (nums[i % numsSize]) {
            oneCount++;
        }
        
        maxOnes = oneCount > maxOnes ? oneCount : maxOnes;
    }
    
    return totalOnes - maxOnes;
}
