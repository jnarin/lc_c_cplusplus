/*
Link: https://leetcode.com/problems/buddy-strings/
Problem: 859. Buddy Strings
*/

#define MAXALPHA    (26)
#define ATON(a)     ((a) - 'a')

bool buddyStrings(char * s, char * goal){
    int s_len = strlen(s), goal_len = strlen(goal);
    
    if (s_len != goal_len){
        return false;
    }
    
    int map_s[MAXALPHA], map_goal[MAXALPHA], i, u = 0;
    memset(map_s, 0, sizeof(map_s));

    
    for (i = 0; i < s_len; i++){
        if (map_s[ATON(s[i])]++ == 0){
            u++;
        }
    }
    
    if (strcmp(s, goal) == 0 && u < s_len){
        return true;
    }
    
    
    int diff_idx = 0, diff[s_len];
    memset(diff, 0, sizeof(diff));
    
    for (i = 0; i < s_len; i++){
        if (s[i] != goal[i]){
            diff[diff_idx++] = i;
        }
    }
    
    return diff_idx == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];

}