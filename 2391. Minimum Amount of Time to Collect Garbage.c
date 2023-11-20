/*
Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
Problem: 2391. Minimum Amount of Time to Collect Garbage
*/
int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    int prefix[travelSize + 1], len, i, j;
    int totalPickups, g, m, p;
    char *house;
    
    totalPickups = g = m = p = 0;
    
    prefix[0] = 0;
    for (i = 1; i < travelSize + 1; i++){
        prefix[i] = prefix[i - 1] + travel[i - 1];
    }
    
    for (i = 0; i < garbageSize; i++){
        house = garbage[i];
        len = strlen(house);
        
        for (j = 0; j < len; j++){
            switch(house[j]){
                case 'G':
                    g = i;
                    break;
                case 'M':
                    m = i;
                    break;
                case 'P':
                    p = i;
                    break;
            }
            
            totalPickups++;
        }
    }
    
    return prefix[g] + prefix[m] + prefix[p] + totalPickups;
    
}