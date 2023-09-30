/*
 * Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * Problem: 1437. Check If All 1's Are at Least Length K Places Away
 * */
bool kLengthApart(int* nums, int numsSize, int k){
    int i = 0, p = -1;

    for (i = 0; i < numsSize; i++){
        if (nums[i] != 0){
            p = i;
            break;
        }
    }

    i++;

    for (; i < numsSize; i++){
        if (nums[i] != 1){
            continue;
        }

        if (i - p <= k){
            return false;
        }

        p = i;
    }

    return true;
}
