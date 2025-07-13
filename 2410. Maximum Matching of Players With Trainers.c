/*
Problem: 2410. Maximum Matching of Players With Trainers
Link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), incrCmp);
    qsort(trainers, trainersSize, sizeof(int), incrCmp);

    int i, j;

    for (i = 0, j = 0; i < playersSize; i++, j++) {
        while (j < trainersSize && trainers[j] < players[i]) {
            j++;
        }

        if (j == trainersSize) {
            return i;
        }
    }
    
    return playersSize;
}
