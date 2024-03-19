/*
Link: https://leetcode.com/problems/task-scheduler/
Problem: 621. Task Scheduler
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int leastInterval(char* tasks, int tasksSize, int n){
    int map[26] = {0};
    int max_count = 0, ans = 0, i;
    
    for (i = 0; i < tasksSize; i++){
        int c = tasks[i] - 'A';
        map[c]++;
        max_count = MAXVAL(max_count, map[c]);
    }
    
    ans = (max_count - 1) * (n + 1);
    for (i = 0; i < 26; i++){
        if (map[i] == max_count){
            ans++;
        }
    }
    
    return tasksSize > ans ? tasksSize : ans;
}