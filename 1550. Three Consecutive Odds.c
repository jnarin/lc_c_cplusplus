/*
 * Link: https://leetcode.com/problems/three-consecutive-odds/
 * Problem: 1550. Three Consecutive Odds
 * */

bool threeConsecutiveOdds(int* arr, int arrSize){
    if (arrSize < 3){
        return false;
    }

    int i;
    for (i = 1; i < arrSize - 1; i++){
        if ((arr[i - 1] & arr[i] & arr[i + 1]) & 1){
            return true;
        }
    }

    return false;
}
