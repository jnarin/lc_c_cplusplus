/*
Link: https://leetcode.com/problems/is-graph-bipartite/
Problem: 785. Is Graph Bipartite?
*/

static bool isValidColor(int **graph, int *color, int graphSize, int *graphColSize, int col, int node){
    assert(graph);
    assert(color);
    assert(graphSize);
    
    if (color[node] != 0){
        return color[node] == col;
    }
    
    color[node] = col;
    
    int i = 0;
    
    while (i < graphColSize[node]){
        assert(graph[node]);
        
        if (false == isValidColor(graph, color, graphSize, graphColSize, -col, graph[node][i])){
            return false;
        }
        
        i++;
    }
    
    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    assert(graph);
    assert(graphColSize);
    
    int i, color[graphSize];
    memset(color, 0, sizeof(color));
    
    for (i = 0; i < graphSize; i++){
        if (color[i] == 0 && !isValidColor(graph, color, graphSize, graphColSize, 1, i)){
            return false;
        }
    }
    
    return true;

}