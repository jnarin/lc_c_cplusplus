/*
Problem: 3606. Coupon Code Validator
Link: https://leetcode.com/problems/coupon-code-validator/
*/

static int isValidCode(const char* s) {
    if (s == NULL || *s == '\0') {
        return 0;
    }

    for (const char* p = s; *p != '\0'; ++p) {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || *p == '_')) {
            return 0;
        }
    }

    return 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    const char *validBusinessLines[] = {"electronics", "grocery", "pharmacy", "restaurant"};
    int validCount = 4;
    int idx[codeSize], idxCount = 0, i;

    for (i = 0; i < codeSize; ++i) {
        if (isActive[i]) {
            int isValidBusiness = 0;
            for (int j = 0; j < validCount; ++j) {
                if (strcmp(businessLine[i], validBusinessLines[j]) == 0) {
                    isValidBusiness = 1;
                    break;
                }
            }
            if (isValidBusiness && isValidCode(code[i])) {
                idx[idxCount++] = i;
            }
        }
    }

    for (i = 0; i < idxCount - 1; ++i) {
        for (int j = i + 1; j < idxCount; ++j) {
            int cmpBusiness = strcmp(businessLine[idx[i]], businessLine[idx[j]]);
            if (cmpBusiness > 0 || (cmpBusiness == 0 && strcmp(code[idx[i]], code[idx[j]]) > 0)) {
                int temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
    }

    char **result = (char **)malloc(idxCount * sizeof(char *));
    for (i = 0; i < idxCount; ++i) {
        result[i] = code[idx[i]];
    }

    *returnSize = idxCount;
    return result;
}

