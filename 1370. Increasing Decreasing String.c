/*
 * Link: https://leetcode.com/problems/increasing-decreasing-string/
 * Problem: 1370. Increasing Decreasing String
 * */

#define MAXLEN      (500)
#define MAXALPHA    (26)
static int arraySum(int *arr, int len){
    int i, ans = 0;

    for (i = 0; i < len; i++){
        ans += arr[i];
    }

    return ans;
}

char * sortString(char * s){
    char *ans = calloc(MAXLEN + 1, sizeof(char));
    int idx = 0;
    int i, len = strlen(s);
    int map[MAXALPHA];
    memset(map, 0, sizeof(map));
    int c;

    for (i = 0; i < len; i++){
        map[s[i] - 'a']++;
    }

    while (1){
        if (arraySum(map, MAXALPHA) == 0){
            break;
        }

        c = -1;
        for (i = 0; i < MAXALPHA; i++){
            if (map[i] && i > c){
                c = i;
                ans[idx++] = c + 'a';
                map[i]--;
            }
        }

        c = MAXALPHA;
        for (i = MAXALPHA - 1; i >= 0; i--){
            if (map[i] && i < c){
                c = i;
                ans[idx++] = c + 'a';
                map[i]--;
            }
        }
    }

    return ans;
}
