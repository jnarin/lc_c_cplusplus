/*
 * Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
 * Problem: 2642. Design Graph With Shortest Path Calculator
 * */



#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

#define MAX_DIST    (int)(1e9+7)

typedef struct {
    int numNodes;
    int **graph;
} Graph;


Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph *obj = calloc(1, sizeof(Graph));
    int i, j;

    obj->numNodes = n;
    obj->graph = calloc(n, sizeof(int *));

    for (i = 0; i < obj->numNodes; i++){
        obj->graph[i] = calloc(obj->numNodes, sizeof(int));;
        for (j = 0; j < obj->numNodes; j++){
            obj->graph[i][j] = MAX_DIST;
        }
    }

    for (i = 0; i < edgesSize; i++){
        obj->graph[edges[i][0]][edges[i][1]] = edges[i][2];
    }

    return obj;
}

void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    obj->graph[edge[0]][edge[1]] = edge[2];

}

int graphShortestPath(Graph* obj, int node1, int node2) {
    bool visited[obj->numNodes];
    int distance[obj->numNodes];
    int i, j, t;

    memset(visited, 0, sizeof(visited));
    for (i = 0; i < obj->numNodes; i++){
        distance[i] = MAX_DIST;
    }

    distance[node1] = 0;

    for (i = 0; i < obj->numNodes; i++){
        t = -1;
        for (j = 0; j < obj->numNodes; j++){
            if (visited[j] == false && (t == -1 || distance[t] > distance[j])){
                t = j;
            }
        }

        visited[t] = true;
        for (j = 0; j < obj->numNodes; j++){
            distance[j] = MINVAL(distance[j], distance[t] + obj->graph[t][j]);
        }
    }

    return distance[node2] >= MAX_DIST ? -1 : distance[node2];
}

void graphFree(Graph* obj) {
    int i;

    for (i = 0; i < obj->numNodes; i++){
        free(obj->graph[i]);
    }

    free(obj);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);

 * int param_2 = graphShortestPath(obj, node1, node2);

 * graphFree(obj);
*/
