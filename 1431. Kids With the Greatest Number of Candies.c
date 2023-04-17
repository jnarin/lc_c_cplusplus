/*
Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
Problem: 1431. Kids With the Greatest Number of Candies
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    assert(candies);
    assert(returnSize);
    
    bool *ans = calloc(candiesSize, sizeof(bool));
    *returnSize = candiesSize;
    
    
    int i, max = INT_MIN;
    
    for (i = 0; i < candiesSize; i++){
        max = candies[i] > max ? candies[i] : max;
    }
    
    
    for (i = 0; i < candiesSize; i++){
        ans[i] = ((candies[i] + extraCandies) >= max) ? true : false;
    }
    
    
    return ans;
}