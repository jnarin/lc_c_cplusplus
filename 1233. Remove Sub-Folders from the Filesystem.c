/*
Problem: 1233. Remove Sub-Folders from the Filesystem
Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int incrCmp(const void *a, const void *b) {
    char *pa = *(char**)a;
    char *pb = *(char**)b;

    int lena = strlen(pa);
    int lenb = strlen(pb);

    int i, j;

    for (i = 0, j = 0; i < lena && j < lenb; i++, j++) {
        if (pa[i] == pb[j]) {
            continue;
        } else {
            return pa[i] - pb[j];
        }
    }

    return lena - lenb;
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char*), incrCmp);
    int i, idx = 0;

    char **result = calloc(folderSize, sizeof(char*)), *p = NULL;
    
    for(i = 0; i < folderSize; i++) {
        if (p && strstr(folder[i], p) == folder[i] && folder[i][strlen(p)] == '/') {
            continue;
        }

        p = folder[i];
        result[idx] = calloc(strlen(folder[i]) + 1, sizeof(char));
        strcpy(result[idx], folder[i]);
        idx++;
    }

    *returnSize = idx;
    
    return result;
}
