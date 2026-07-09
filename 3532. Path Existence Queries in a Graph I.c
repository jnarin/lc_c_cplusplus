/*
Problem: 3532. Path Existence Queries in a Graph I
Link: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int graph[n], count = 0, i, idx = 0;
    bool *ans = calloc(queriesSize, sizeof(bool));

    memset(graph, 0, sizeof(graph));

    for (i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] > maxDiff) {
            count++;
        }

        graph[i] = count;
    }

    for (i = 0; i < queriesSize; i++) {
        ans[idx++] = graph[queries[i][0]] == graph[queries[i][1]];
    }
    
    *returnSize = idx;

    return ans;
}
