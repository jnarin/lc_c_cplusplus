/*
Link: https://leetcode.com/problems/find-unique-binary-string/
Problem: 1980. Find Unique Binary String
*/

char* findDifferentBinaryString(char** nums, int numsSize) {
    char *ans = calloc (numsSize + 1, sizeof(char));
    int i, idx = 0;
    
    for (i = 0; i < numsSize; i++){
        ans[idx++] = nums[i][i] == '0' ? '1' : '0';
    }
    
    return ans;    
}