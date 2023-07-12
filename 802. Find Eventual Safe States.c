/*
Link: https://leetcode.com/problems/find-eventual-safe-states/
Problem: 802. Find Eventual Safe States
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef enum {
    UNVISITED_E  = 0,
    VISITING_E,
    VISITED_E,
}states_e;

static bool hasCycle(int** graph, int graphSize, int* graphColSize, int u, int *state){
    if (state[u] == VISITING_E){
        return true;
    }
    
    if (state[u] == VISITED_E){
        return false;
    }
    
    int i;
    state[u] = VISITING_E;
    for (i = 0; i < graphColSize[u]; i++){
        if (hasCycle(graph, graphSize, graphColSize, graph[u][i], state) == true){
            return true;
        }
    }
    state[u] = VISITED_E;
    
    return false;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int *ans = calloc(graphSize, sizeof(int)), state[graphSize], i, idx = 0;
    memset(state, 0, sizeof(state));
    
    for (i = 0; i < graphSize; i++){
        if (hasCycle(graph, graphSize, graphColSize, i, state) == false){
            ans[idx++] = i;
        }
    }
    
    *returnSize = idx;
    return ans;
}