/*
Problem: 2126. Destroying Asteroids
Link: https://leetcode.com/problems/destroying-asteroids/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    unsigned long m = mass;
    qsort(asteroids, asteroidsSize, sizeof(int), incrCmp);

    for (int i = 0; i < asteroidsSize; i++) {
        if (m < asteroids[i]) {
            return false;
        }

        m += asteroids[i];
    }
    
    return true;
}
