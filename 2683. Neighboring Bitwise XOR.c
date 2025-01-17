/*
Problem: 2683. Neighboring Bitwise XOR
Link: https://leetcode.com/problems/neighboring-bitwise-xor/
*/

static int xorArraySum(int *array, int size) {
    int ans = 0, i;

    for (i = 0; i < size; i++) {
        ans ^= array[i];
    }

    return ans;
}

bool doesValidArrayExist(int* derived, int derivedSize) {
    return xorArraySum(derived, derivedSize) == 0;
}
