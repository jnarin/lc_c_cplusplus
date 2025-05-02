/*
Problem: 838. Push Dominoes
Link: https://leetcode.com/problems/push-dominoes/
*/

char * pushDominoes(char * dominoes){
    int n = strlen(dominoes);
    int left[n], right[n], sum[n], cmd = 0;
    int i, p = 0;
    
    for (i = 0; i < n; i++){
        switch (dominoes[i]){
            case 'R':
                cmd = n;
                break;
            
            case 'L':
                cmd = 0;
                break;
            
            case '.':
                cmd = (cmd - 1) > 0 ? cmd - 1 : 0;
                break;
            
            default:
                assert(0);
        }
        
        right[i] = cmd;
    }
    
    for (i = n - 1; i >= 0; i--){
        switch(dominoes[i]){
            case 'L':
                cmd = n;
                break;
                
            case 'R':
                cmd = 0;
                break;
                
            case '.':
                cmd = (cmd - 1) > 0 ? cmd - 1 : 0;
                break;
                
            default:
                assert(0);
        }
        
        left[i] = cmd * (-1);
    }
    
    for (i = 0; i < n; i++){
        sum[i] = right[i] + left[i];
        
        if (sum[i] == 0){
            dominoes[i] = '.';
        }
        else if (sum[i] > 0){
            dominoes[i] = 'R';
        } else {
            dominoes[i] = 'L';
        } 
    }
    
    return dominoes;

}
