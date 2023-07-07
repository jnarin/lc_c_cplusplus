/*
Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
Problem: 2024. Maximize the Confusion of an Exam
*/

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxConsecutiveAnswers(char * answerKey, int k){
    int ans, maxCount, countT, countF, l, r, len;
    ans = maxCount = countT = countF = l = r = 0;
    len = strlen(answerKey);
    
    while (r < len){
        switch(answerKey[r]){
            case 'T':
                countT++;
                maxCount = MAXVAL(maxCount, countT);
                break;
            
            case 'F':
                countF++;
                maxCount = MAXVAL(maxCount, countF);
                break;
            
            default:
                assert(0);
        }
        
        while (maxCount + k < r - l + 1){
            switch(answerKey[l]){
                case 'T':
                    countT--;
                    break;
                    
                case 'F':
                    countF--;
                    break;
                    
                default:
                    assert(0);
            }
            
            l++;
        }
        
        ans = MAXVAL(ans, r - l + 1);
        r++;
    }
    
    return ans;
}