/*
Problem: 264. Ugly Number II
Link: https://leetcode.com/problems/ugly-number-ii/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int nthUglyNumber(int n) {
    int nums[n], idx;
    int i2, i3, i5, n2, n3, n5, nxt;
    
    memset(nums, 0, sizeof(nums));
    idx = i2 = i3 = i5 = 0;
    nums[idx++] = 1;
    
    while (idx < n) {
        n2 = nums[i2] * 2;
        n3 = nums[i3] * 3;
        n5 = nums[i5] * 5;
        
        nxt = MINVAL(MINVAL(n2, n3), n5);
        
        i2 = nxt == n2 ? i2 + 1 : i2;
        i3 = nxt == n3 ? i3 + 1 : i3;
        i5 = nxt == n5 ? i5 + 1 : i5;
        
        nums[idx++] = nxt;
    }
    
    return nums[n - 1];    
}
