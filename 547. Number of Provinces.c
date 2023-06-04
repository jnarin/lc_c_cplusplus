/*
 * Link: https://leetcode.com/problems/number-of-provinces/
 * Problem: 547. Number of Provinces
 * */

typedef struct {
    int *id, count;
}unionFind_t;

static int find(unionFind_t *uf, int u){
    uf->id[u] = uf->id[u] == u ? u : find(uf, uf->id[u]);    

    return uf->id[u];
}

static void unionFind(unionFind_t *uf, int u, int v){
    int i, j;
    i = find(uf, u);
    j = find(uf, v);
    
    if (i == j){
        return;
    }
    
    uf->id[i] = j;
    uf->count--;
    
    return;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    unionFind_t uf;
    int i, j;
    
    uf.id = calloc(isConnectedSize, sizeof(int));
    uf.count = isConnectedSize;
    
    for (i = 0; i < isConnectedSize; i++){
        uf.id[i] = i;
    }
    
    for (i = 0; i < isConnectedSize; i++){
        for (j = i; j < isConnectedColSize[i]; j++){
            if (isConnected[i][j] == 1){
                unionFind(&uf, i, j);
            }
        }
    }
    
    free(uf.id);
    
    return uf.count;
}

