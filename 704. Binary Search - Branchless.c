/*
Link: https://leetcode.com/problems/binary-search/
Problem: 704. Binary Search
*/

#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

int search(int* nums, int numsSize, int target){
    int low = 0, high = numsSize - 1, mid;
    while (low <= high){
        mid = MIDVAL(low, high);

        if (nums[mid] == target){
            return mid;
        }

        int newLow = mid + 1, newHigh = mid - 1;
        int condition = nums[mid] < target;
        int conditionTrueMask = -condition;
        int conditionFalseMask = -(1 - condition);

        low += conditionTrueMask & (newLow - low);
        high += conditionFalseMask & (newHigh - high);
    }

    return -1;
}
