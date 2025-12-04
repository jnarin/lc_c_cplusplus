/*
Problem: 2211. Count Collisions on a Road
Link: https://leetcode.com/problems/count-collisions-on-a-road/
*/

int countCollisions(char* directions) {
    int len = strlen(directions), l = 0, r = len - 1, collisions = 0, i;

    while (l < len && directions[l] == 'L') {
        l++;
    }

    while (r >= 0 && directions[r] == 'R') {
        r--;
    }

    for (i = l; i <= r; i++) {
        if (directions[i] != 'S') {
            collisions++;
        }
    }

    return collisions;
}
