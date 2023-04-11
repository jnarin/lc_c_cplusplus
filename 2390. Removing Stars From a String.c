/*
Link: https://leetcode.com/problems/removing-stars-from-a-string/
Problem: 2390. Removing Stars From a String
*/

char * removeStars(char * s){
    assert(s);
    int len = strlen(s), i;
    
    char *stack, c;
    stack = calloc(len + 1, sizeof(char));
    
    int top = 0;
    
    while (i < len){
        c = s[i++];
        if (c != '*'){
            stack[top] = c;
            top++;
            continue;
        }
        
        if (top > 0){
            top--;
            stack[top] = '\0';    
        }
    }
    
    return stack;
}