/*
Problem: 551. Student Attendance Record I
Link: https://leetcode.com/problems/student-attendance-record-i/
*/

bool checkRecord(char* s) {
    int absentCount = 0, lateCount = 0;
    
    while (*s) {
        switch (*s) {
            case 'A':
                if (absentCount == 1) {
                    return false;
                }
                absentCount++;
                // Fallthrough
                
            case 'P':
                lateCount = 0;
                break;
                
            case 'L':
                if (lateCount == 2) {
                    return false;
                }
                lateCount++;
                break;
            
                
        }
        
        s++;
    }
    
    return true;
}