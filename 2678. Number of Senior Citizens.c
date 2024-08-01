/*
Problem: 2678. Number of Senior Citizens
Link: https://leetcode.com/problems/number-of-senior-citizens/
*/

int countSeniors(char ** details, int detailsSize){
    int ans = 0,  i, j, age, len;
    char *p;
    
    for (i = 0; i < detailsSize; i++)  {
        len = strlen(details[i]);
        p = details[i];
        
        for (j = 0; j < len; j++) {
            if (isalpha(p[j])){
                break;
            }
        }
        
        j++;
        age = ((p[j] - '0') * 10) + (p[j + 1] - '0');
        ans = age > 60 ? ans + 1 : ans;
    }

    return ans;
}
