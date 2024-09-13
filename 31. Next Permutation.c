/*
Problem: 31. Next Permutation
Link: https://leetcode.com/problems/next-permutation/
*/

static void reverse(int * nums, int l, int r){
    int t;

    while (l < r){
        t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
        
        l++;
        r--;
    }
}

void nextPermutation(int* nums, int numsSize){
    int i, j, t;
    
    i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]){
        i--;
    }
    
    
    if (i >= 0){
        j = numsSize - 1;
        while (j && nums[j] <= nums[i]){
            j--;
        }
        
        t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
        
    reverse(nums, i + 1, numsSize - 1); 
    
    return;
}
