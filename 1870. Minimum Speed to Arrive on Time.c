/*
Link: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
Problem: 1870. Minimum Speed to Arrive on Time
*/

#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

static bool checkTime(int *dist, int distSize, int s, double hour){
    double ans = 0, cost;
    int i;
    
    for (i = 0; i < distSize; i++){
        cost = dist[i] * 1.0 / s;
        ans += (i == distSize - 1) ? cost : ceil(cost);
    }
    
    return ans <= hour;
}

int minSpeedOnTime(int* dist, int distSize, double hour){
    int l = 1, r = 1e7, m;
    
    while (l < r){
        m = MIDVAL(l, r);
        
        if (checkTime(dist, distSize, m, hour) == true){
            r = m;
        } else {
            l = m + 1;
        }
    }

    return checkTime(dist, distSize, l, hour) ? l : -1;
}