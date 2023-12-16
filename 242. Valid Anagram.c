/*
 * Link: https://leetcode.com/problems/valid-anagram/
 * Problem: 242. Valid Anagram
 * */


bool isAnagram(char * s, char * t){
    int s_len, t_len;
    int s_map[26] = {0}, t_map[26] = {0};
    int i;

    s_len = strlen(s);
    t_len = strlen(t);

    if (s_len != t_len){
        return false;
    }

    for (i = 0; i < s_len; i++){
        s_map[s[i] - 'a']++;
        t_map[t[i] - 'a']++;
    }

    return 0 == memcmp(s_map, t_map, sizeof(s_map)) ? true : false;
}
