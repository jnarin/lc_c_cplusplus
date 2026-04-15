/*
Problem: 2515. Shortest Distance to Target String in a Circular Array
Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
*/
int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int i;

    for (i = 0; i < wordsSize; i++) {
        if (strcmp(words[(startIndex + i + wordsSize) % wordsSize], target) == 0) {
            return i;
        }

        if (strcmp(words[(startIndex - i + wordsSize) % wordsSize], target) == 0) {
            return i;
        }
    }

    return -1;
}
