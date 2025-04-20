/*
Problem: 781. Rabbits in Forest
Link: https://leetcode.com/problems/rabbits-in-forest/
*/

#define MAX_NUM (1000 + 1)

int numRabbits(int* answers, int answersSize) {
    int ans = 0, f[MAX_NUM] = {0}, i;

    for (i = 0; i < answersSize; i++) {
        ans += f[answers[i]] % (answers[i] + 1) == 0 ? answers[i] + 1 : 0;

        f[answers[i]]++;
    }
    
    return ans;
}
