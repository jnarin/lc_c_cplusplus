/*
 * Problem: 165. Compare Version Numbers
 * Link: https://leetcode.com/problems/compare-version-numbers/
 * */

#define CHAR_TO_NUM(c) ((c) - '0')

int compareVersion(char * version1, char * version2){
    int i, j, v1, v2, len1, len2;
    i = j = 0;

    len1 = strlen(version1);
    len2 = strlen(version2);

    while (i < len1 || j < len2){
        v1 = v2 = 0;

        while (i < len1 && version1[i] != '.'){
            v1 = (10 * v1) + CHAR_TO_NUM(version1[i]);
            i++;
        }

        while (j < len2 && version2[j] != '.'){
            v2 = (10 * v2) + CHAR_TO_NUM(version2[j]);
            j++;
        }

        if (v1 < v2){
            return -1;
        }

        if (v1 > v2){
            return 1;
        }

        i++;
        j++;
    }

    return 0;

}
