/*
 * Link: https://leetcode.com/problems/poor-pigs/
 * Problem: 458. Poor Pigs
 * */

int poorPigs(int buckets, int minutesToDie, int minutesToTest){
    int t = minutesToTest / minutesToDie, ans = 0;
    while (pow(t + 1, ans) < buckets){
        ans++;
    }

    return ans;
}
