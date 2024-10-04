/*
Problem: 2491. Divide Players Into Teams of Equal Skill
Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

long long dividePlayers(int* skill, int skillSize) {
    qsort(skill, skillSize, sizeof(int), incrCmp);
    
    long long ans = 0;
    int l = 0, r = skillSize - 1, t = skill[l] + skill[r];
    
    while (l <= r) {
        if (t != skill[l] + skill[r]) {
            return -1;
        }
        
        ans += skill[l] * skill[r];
        
        l++;
        r--;
    }
    
    return ans;    
}
