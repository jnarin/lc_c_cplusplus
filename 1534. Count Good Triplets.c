/*
Problem: 1534. Count Good Triplets
Link: https://leetcode.com/problems/count-good-triplets/
*/

int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int ans = 0, i, j, k;

    for (i = 0; i < arrSize; i++) {
        for (j = i + 1; j < arrSize; j++) {
            for (k = j + 1; k < arrSize; k++) {
                if (abs(arr[i] - arr[j]) <= a 
                    && abs(arr[j] - arr[k]) <= b 
                    && abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
            }
        }
    }

    return ans;
}
