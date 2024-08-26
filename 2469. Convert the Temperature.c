/*
Problem: 2469. Convert the Temperature
Link: https://leetcode.com/problems/convert-the-temperature/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double *ans = calloc(2, sizeof(double));
    *returnSize = 2;
    
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.8 + 32.00;
    
    return ans;    
}
