/*
Link: https://leetcode.com/problems/longest-cycle-in-a-graph/
Problem: 2360. Longest Cycle in a Graph
*/

#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int longestCycle(int* edges, int edgesSize){
    int ans, count, i, start, u;
    int visited[edgesSize];
    
    ans = count = -1;
    memset(visited, 0, sizeof(visited));

    for (i = 0; i < edgesSize; i++){
        if (visited[i]){
            continue;
        }
        
        u = i;
        start = count;
        
        while (u != -1 && !visited[u]){
            visited[u] = count++;
            u = edges[u];
        }
        
        if (u != -1 && visited[u] >= start){
            ans = MAX_VAL(ans, count - visited[u]);
        }
    }

    return ans;
}
