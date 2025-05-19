/*
Problem: 3024. Type of Triangle
Link: https://leetcode.com/problems/type-of-triangle/
*/

char* triangleType(int* nums, int numsSize) {
    char *ans = calloc(12, sizeof(char)), *type[] = {"equilateral", "isosceles", "scalene", "none"};
    
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
        strcpy(ans, type[0]);
        goto exit;
    }

    if (nums[0] + nums[1] <= nums[2] 
        || nums[1] + nums[2] <= nums[0] 
        || nums[2] + nums[0] <= nums[1] ) {
        strcpy(ans, type[3]);
        goto exit;
    }


    if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
        strcpy(ans, type[1]);
        goto exit;
    }

    strcpy(ans, type[2]);

exit:
    return ans;
}
