/*
 * Link: https://leetcode.com/problems/find-the-winner-of-an-array-game/
 * Problem: 1535. Find the Winner of an Array Game
 * */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int maxElement(int *arr, int arrSize){
    int i, ans = INT_MIN;

    for (i = 0; i < arrSize; i++){
        ans = MAXVAL(ans, arr[i]);
    }

    return ans;
}

int getWinner(int* arr, int arrSize, int k) {
    int ans = arr[0], i, wins = 0;

    if (k >= arrSize){
        return maxElement(arr, arrSize);
    }

    for (i = 1; i < arrSize; i++){
        if (wins >= k){
            break;
        }

        if (arr[i] > ans){
            ans = arr[i];
            wins = 1;
        } else {
            wins++;
        }
    }

    return ans;
}
