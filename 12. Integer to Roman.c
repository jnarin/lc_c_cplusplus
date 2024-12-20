/*
Problem: 12. Integer to Roman
Link: https://leetcode.com/problems/integer-to-roman/submissions/
*/

#define MAX_BUFFER_SIZE (1000)
char * intToRoman(int num){
    char *ans = calloc(MAX_BUFFER_SIZE, sizeof(char));
    int idx = 0;

    while (num){
        assert(idx < MAX_BUFFER_SIZE);

        if (num >= 1000) {
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'M';
                num -= 1000;
                continue;
            }
            
            if (num >= 900) {
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++]= 'C';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++]= 'M';
                num -= 900;
                continue;
            }
            
            if (num >= 500){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++]= 'D';
                num -= 500;
                continue;
            }
            
            if (num >= 400){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'C';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'D';
                num -= 400;
                continue;
            }
            
            if (num >= 100){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'C';
                num -= 100;
                continue;
            }
            
            if (num >= 90){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'X';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'C';
                num -= 90;
                continue;
            }
            
            if (num >= 50){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'L';
                num -= 50;
                continue;
            }
            
            if (num >= 40){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'X';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'L';
                num -= 40;
                continue;
            }
            
            if (num >= 10){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++]= 'X';
                num -= 10;
                continue;
            }
            
            if (num >= 9){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'I';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'X';
                num -= 9;
                continue;
            }
            
            if (num >= 5){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'V';
                num -= 5;
                continue;
            }
            
            if (num >= 4){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'I';
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'V';
                num -= 4;
                continue;
            }
            
            if (num >= 1){
                assert(idx < MAX_BUFFER_SIZE);
                ans[idx++] = 'I';
                num -= 1;
                continue;
            }
    }

    return ans;
}
