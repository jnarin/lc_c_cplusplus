/*
Problem: 1395. Count Number of Teams
Link: https://leetcode.com/problems/count-number-of-teams/
*/

int numTeams(int* rating, int ratingSize) {
    int ans = 0, i, j, lLesser, lGreater, rLesser, rGreater;
    
    for (i = 1; i < ratingSize - 1; i++) {
        lLesser = lGreater = 0;
        
        for (j = 0; j < i; j++) {
            if (rating[j] < rating[i]) {
                lLesser++;
            } else {
                lGreater++;
            }
        }
        
        rLesser = rGreater = 0;
        
        for (j = i + 1; j < ratingSize; j++) {
            if (rating[j] < rating[i]) {
                rLesser++;
            } else {
                rGreater++;
            }
        }
        
        ans += lLesser * rGreater + lGreater * rLesser;
    }
    
    return ans;
}
