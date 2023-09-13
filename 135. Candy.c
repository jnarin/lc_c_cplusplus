/*
Link: https://leetcode.com/problems/candy/
Problem: 135. Candy
*/
#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int candy(int* ratings, int ratingsSize){
    int candies[ratingsSize], i, ans = 0;
    
    for(i = 0; i < ratingsSize; i++){
        candies[i] = 1;
    }
    
    for (i = 1; i < ratingsSize; i++){
        candies[i] = ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : candies[i];
    }
    
    for (i = ratingsSize - 2; i >= 0; i--){
        candies[i] = ratings[i] > ratings[i + 1] ? MAXVAL(candies[i], candies[i + 1] + 1) : candies[i];
    }
    
    for (i = 0; i < ratingsSize; i++){
        ans += candies[i];
    }
    
    return ans;
}