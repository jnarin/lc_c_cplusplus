/*
Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal/
Problem: 2448. Minimum Cost to Make Array Equal
*/
#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

static int getMax(int *nums, int numsSize){
    int ans = nums[0], i;
    
    for (i = 1; i < numsSize; i++){
        ans = MAXVAL(ans, nums[i]);
    }
    
    return ans;
}

static int getMin(int *nums, int numsSize){
    int ans = nums[0], i;
    
    for (i = 1; i < numsSize; i++){
        ans = MINVAL(ans, nums[i]);
    }
    
    return ans;
}

static long long getCost(int *nums, int *costs, int numsSize, int t){
    long long ans = 0;
    int i;
    
    for (i = 0; i < numsSize; i++){
        ans += (long long)abs(nums[i] - t) * (long long)costs[i];
    }
    
    return ans;
}

long long minCost(int* nums, int numsSize, int* cost, int costSize){
    long long ans = 0;
    int l, r, m;
    long long c1, c2;
    
    l = getMin(nums, numsSize);
    r = getMax(nums, numsSize);
    
    while (l < r){
        m = (l + r) >> 1;
        
        c1 = getCost(nums, cost, numsSize,  m);
        c2 = getCost(nums, cost, numsSize, m + 1);
        
        ans = MINVAL(c1, c2);
        if (c1 < c2){
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    return ans;
}