/*
Link: https://leetcode.com/problems/daily-temperatures/
Problem: 739. Daily Temperatures
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    int *ans = calloc(temperaturesSize, sizeof(int));
    *returnSize = temperaturesSize;
    
    struct stack {
        int value, index;
    }s[temperaturesSize];
    memset(s, 0, sizeof(s));

    int i, s_size = 0;

    for (i = 0; i < temperaturesSize; i++){
        while (s_size > 0 && s[s_size - 1].value < temperatures[i]){
            ans[s[s_size - 1].index] = i -  s[s_size - 1].index;
            s_size--;
        }

        s[s_size].value = temperatures[i];
        s[s_size].index = i;
        s_size++;
    }

    return ans;
}