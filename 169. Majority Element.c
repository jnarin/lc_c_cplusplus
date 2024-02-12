/*
Link: https://leetcode.com/problems/majority-element/
Problem: 169. Majority Element
*/

int majorityElement(int* nums, int numsSize){
    int max, count, i;

    i = 0;
    max = nums[i++];
    count  = 1;

    for (; i < numsSize; i++){
        if (max == nums[i]){
            count++;
        } else {
            count--;
            if (count == 0){
                max = nums[i];
                count = 1;
            }
        }
    }

    return max;
}

