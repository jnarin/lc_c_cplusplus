/*
Problem: 495. Teemo Attacking
Link: https://leetcode.com/problems/teemo-attacking/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int i, total = 0;

    if(timeSeriesSize == 0) {
        return 0;
    }

    for(i = 1; i < timeSeriesSize; i++){
        total += MINVAL(timeSeries[i] - timeSeries[i-1], duration);
    }

    return total + duration;
}
