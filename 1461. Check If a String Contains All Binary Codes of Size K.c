/*
Problem:: 1461. Check If a String Contains All Binary Codes of Size K
Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

bool hasAllCodes(char* s, int k) {
    int len = strlen(s), i;

    if (len < k){
        return false;
    }

    int total = 1 << k;
    int mask = total - 1;
    int hash = 0;
    int bitset_size = (total + 31) / 32;
    unsigned int* seen = calloc(bitset_size, sizeof(unsigned int));
    
    for (i = 0; i < len; i++) {
        hash = ((hash << 1) & mask) | (s[i] - '0');
        if (i >= k - 1) {
            int idx = hash / 32;
            int bit = hash % 32;
            if (!(seen[idx] & (1U << bit))) {
                seen[idx] |= (1U << bit);
                total--;
                if (total == 0) {
                    free(seen);
                    return true;
                }
            }
        }
    }

    free(seen);
    return false;
}
