/*
Problem: 2011. Final Value of Variable After Performing Operations
Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
*/

static char getOp(char *operation){
    int i;
    
    for (i = 0; operation[i]; i++){
        switch(operation[i]){
            case '-':
                return '-';
            case '+':
                return '+';
            default:
                break;
        }
    }
    
    return '0';
}

int finalValueAfterOperations(char ** operations, int operationsSize){
    int ans = 0, i;
    
    for (i = 0; i < operationsSize; i++){
        switch (getOp(operations[i])){
            case '+':
                ans++;
                break;
            case '-':
                ans--;
                break;
            default:
                // Error, unexpected input
                return -1;
        }
    }
    
    return ans;

}
