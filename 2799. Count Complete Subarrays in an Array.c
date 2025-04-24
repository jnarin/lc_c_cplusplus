/*
Problem: 2799. Count Complete Subarrays in an Array
Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
*/

#define MAX_VAL (100001)

int countCompleteSubarrays(int* nums, int numsSize) {
    int ans = 0, i = 0, j = 0, cnt = 0, n = 0;
    int map[MAX_VAL] = {0}, vis[MAX_VAL] = {0};

    for (i = 0; i < numsSize; i++) {
        if (!vis[nums[i]]) {
            n++;
            vis[nums[i]] = 1;
        }
    }

    for (i = 0; i < numsSize; i++) {
        if (!map[nums[i]]) {
            cnt++;
        }

        map[nums[i]]++;

        while (cnt == n) {
            ans += numsSize - i;
            map[nums[j]]--;
            if (!map[nums[j]]) {
                cnt--;
            }
            
            j++;
        }
    }

    return ans;
   
}
