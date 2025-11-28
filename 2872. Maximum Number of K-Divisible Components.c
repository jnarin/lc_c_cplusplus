/*
Problem: 2872. Maximum Number of K-Divisible Components
Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/
*/

typedef struct Node {
    int neighbor;
    struct Node* next;
} Node;

typedef struct {
    int node;
    int parent;
    int phase;
} StackItem;

int maxKDivisibleComponents(int n, int** edges, int edgesSize, int* edgesColSize, int* values, int valuesSize, int k) {
    int ans = 0, i;
    Node **adjList = calloc(n, sizeof(Node *));
    
    for (i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        
        Node *newNode = calloc(1, sizeof(Node));
        newNode->neighbor = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;
        
        newNode = calloc(1, sizeof(Node));
        newNode->neighbor = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
    
    StackItem *stack = calloc(n * 2, sizeof(StackItem));
    long long *sums = calloc(n, sizeof(long long));
    int stackTop = 0;
    
    stack[stackTop++] = (StackItem){0, -1, 0};
    
    while (stackTop > 0) {
        StackItem current = stack[--stackTop];
        int node = current.node;
        int parent = current.parent;
        int phase = current.phase;
        
        if (phase == 0) {
            sums[node] = values[node];
            
            stack[stackTop++] = (StackItem){node, parent, 1};
            
            Node *neighbor = adjList[node];
            while (neighbor) {
                if (neighbor->neighbor != parent) {
                    stack[stackTop++] = (StackItem){neighbor->neighbor, node, 0};
                }
                neighbor = neighbor->next;
            }
        } else {
            Node *neighbor = adjList[node];
            while (neighbor) {
                if (neighbor->neighbor != parent) {
                    sums[node] += sums[neighbor->neighbor];
                }
                neighbor = neighbor->next;
            }
            
            ans += sums[node] % k == 0;
        }
    }
    
    free(stack);
    free(sums);

    for (i = 0; i < n; i++) {
        Node *current = adjList[i], *temp;
        while (current) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(adjList);

    return ans;

}
