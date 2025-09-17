/*
Problem: 2197. Replace Non-Coprime Numbers in Array
Link: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
*/

static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

static int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {

    int* stack = calloc(numsSize, sizeof(int));
    int top = -1;

    for (int i = 0; i < numsSize; i++) {
        stack[++top] = nums[i];

        while (top > 0 && gcd(stack[top], stack[top - 1]) > 1) {
            int a = stack[top];
            int b = stack[top - 1];
            stack[--top] = lcm(a, b);
        }
    }

    *returnSize = top + 1;

    return stack;
    
}
