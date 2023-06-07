/*
 * Link: https://leetcode.com/problems/excel-sheet-column-title/
 * Problem: 168. Excel Sheet Column Title
 * */
char * convertToTitle(int columnNumber){
    char *ans = calloc(8, sizeof(char));
    char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", t;
    int r, p = 1, len = 0, i;

    while (columnNumber){
        r = (columnNumber - 1) % 26;
        ans[len++] = map[r];

        columnNumber = (columnNumber - 1) / 26;
    }

    for (i = 0; i < (len >> 1) ; i++){
        t = ans[i];
        ans[i] = ans[len - 1 - i];
        ans[len - 1 - i] = t;
    }
    
    return ans;
}
