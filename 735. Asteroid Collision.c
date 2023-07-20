/*
Link: https://leetcode.com/problems/asteroid-collision/
Problem: 735. Asteroid Collision
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    int *ans, i, idx = 0;
    
    ans = calloc(asteroidsSize, sizeof(int));
    
    for (i = 0; i < asteroidsSize; i++){
        if (asteroids[i] > 0){
            ans[idx++] = asteroids[i];
        } else {
            while (idx && ans[idx - 1] > 0 && ans[idx - 1] < -asteroids[i]){
                idx--;
            }
            
            if (idx == 0 || ans[idx - 1] < 0){
                ans[idx++] = asteroids[i];
            } else if (ans[idx - 1] == -asteroids[i]){
                idx--;
            }
        }
    }
    
    *returnSize = idx;
    return ans;
}