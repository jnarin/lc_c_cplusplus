/*
Problem: 492. Construct the Rectangle
Link: https://leetcode.com/problems/construct-the-rectangle/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int *ans = calloc(2, sizeof(int));

    *returnSize = 2;

    int w = sqrt(area);
    while(area % w != 0) {
        w--;
    }

    ans[0] = area / w;
    ans[1] = w;

    return ans;    
}
