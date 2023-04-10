/*
Link: https://leetcode.com/problems/valid-parentheses/
Problem: 20. Valid Parentheses
*/

bool isValid(char * s){
    assert(s);
    assert(s[0]);
    
    int len = strlen(s);
    assert(len);
    
    char stack[len + 1];
    memset(stack, 0, sizeof(stack));
    
    int i, top = 0;
    char c;
    
    for (i = 0; i < len; i++){
        c = s[i];
        
        switch(c){
            case '(':
            case '{':
            case '[':
                stack[top] = c;
                top++;
                break;;
                
            case ')':
                if (top <= 0 || stack[top - 1] != '('){
                    return false;
                }
                top--;
                break;
                
            case '}':
                if (top <= 0 || stack[top - 1] != '{'){
                    return false;
                }
                top--;
                break;
                
            case ']':
                if (top <= 0 || stack[top - 1] != '['){
                    return false;
                }
                top--;
                break;
                
            default:
                assert(0);
        }
    }
    
    
    return top == 0;

}