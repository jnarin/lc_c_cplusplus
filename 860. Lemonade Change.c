/*
Problem: 860. Lemonade Change
Link: https://leetcode.com/problems/lemonade-change/
*/

bool lemonadeChange(int* bills, int billsSize) {
    int five = 0, ten = 0, i;
    
    for (i = 0; i < billsSize; i++) {
        switch (bills[i]) {
            case 5:
                five++;
                break;
            case 10:
                five--;
                ten++;
                break;
            case 20:
                if (ten > 0) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
                break;
                
            default:
                assert(0);
        }
        
        if (five < 0) {
            return false;
        }
    }
    
    return true;
}
