/*
 * Problem: 925. Long Pressed Name
 * Link: https://leetcode.com/problems/long-pressed-name/
 * */

bool isLongPressedName(char* name, char* typed) {
    int nameLen = strlen(name), typedLen = strlen(typed);
    if (nameLen > typedLen) {
        return false;
    }

    int i = 0, j;

    for (j = 0; j < typedLen; j++) {
        if (i < nameLen && name[i] == typed[j]){
            i++;
        } else  if (j == 0 || typed[j] != typed[j - 1]) {
            return false;
        }
    }

    return i == nameLen;
}
