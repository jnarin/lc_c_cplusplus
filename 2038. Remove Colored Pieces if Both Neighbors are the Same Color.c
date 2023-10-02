/*
 * Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
 * Problem: 2038. Remove Colored Pieces if Both Neighbors are the Same Color
 * */

bool winnerOfGame(char * colors){
    int countA = 0, countB = 0, i, lenColors = strlen(colors);

    for (i = 1; i < lenColors - 1; i++){
        if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]){
            if (colors[i] == 'A'){
                countA++;
            } else {
                countB++;
            }
        }
    }

    return countA > countB;
}
