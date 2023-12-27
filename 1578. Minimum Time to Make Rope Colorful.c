/*
 * Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
 * Problem: 1578. Minimum Time to Make Rope Colorful
 * */

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int minCost(char * colors, int* neededTime, int neededTimeSize){
    int len = strlen(colors);
    int ans = 0, i, c;
    char p;

    if (len == 0){
        return ans;
    }

    p = colors[0];

    for (i = 1; i < neededTimeSize; i++){
        if (p == colors[i]){
            c = MIN(neededTime[i], neededTime[i - 1]);
            ans += c;
            neededTime[i] = MAX(neededTime[i], neededTime[i - 1]);
        } else {
            p = colors[i];
        }
    }

    return ans;
}
