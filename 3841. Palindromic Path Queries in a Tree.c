/*
Problem: 3841. Palindromic Path Queries in a Tree
Link: https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
*/
static void segBuild(int *seg, int segSize, int *maskArr, int n) {
    for (int i = 0; i < n; i++) seg[segSize + i] = maskArr[i];
    for (int i = n; i < segSize; i++) seg[segSize + i] = 0;
    for (int i = segSize - 1; i >= 1; i--) seg[i] = seg[2 * i] ^ seg[2 * i + 1];
}

static void segUpdate(int *seg, int segSize, int pos, int value) {
    int i = segSize + pos;
    seg[i] = value;
    for (i >>= 1; i >= 1; i >>= 1) seg[i] = seg[2 * i] ^ seg[2 * i + 1];
}

/* XOR of seg[l..r] inclusive */
static int segQuery(int *seg, int segSize, int l, int r) {
    int res = 0;
    l += segSize;
    r += segSize + 1;
    while (l < r) {
        if (l & 1) { res ^= seg[l]; l++; }
        if (r & 1) { r--; res ^= seg[r]; }
        l >>= 1; r >>= 1;
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* palindromePath(int n, int** edges, int edgesSize, int* edgesColSize, char* s, char** queries, int queriesSize, int* returnSize) {
    /* Build adjacency list in CSR form */
    int *degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }
    int *adjHead = (int*)malloc((n + 1) * sizeof(int));
    adjHead[0] = 0;
    for (int i = 0; i < n; i++) adjHead[i + 1] = adjHead[i] + degree[i];
    int *fillPos = (int*)malloc(n * sizeof(int));
    memcpy(fillPos, adjHead, n * sizeof(int));
    int *adjList = (int*)malloc(adjHead[n] * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        adjList[fillPos[u]++] = v;
        adjList[fillPos[v]++] = u;
    }
    free(fillPos);
    free(degree);

    /* BFS to get parent/depth/traversal order (parent discovered before child) */
    int *parent = (int*)malloc(n * sizeof(int));
    int *depth = (int*)malloc(n * sizeof(int));
    int *order = (int*)malloc(n * sizeof(int));
    char *visited = (char*)calloc(n, sizeof(char));
    int qt = 0;
    order[qt++] = 0;
    visited[0] = 1;
    parent[0] = -1;
    depth[0] = 0;
    for (int qh = 0; qh < qt; qh++) {
        int u = order[qh];
        for (int e = adjHead[u]; e < adjHead[u + 1]; e++) {
            int v = adjList[e];
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order[qt++] = v;
            }
        }
    }
    free(visited);

    /* Subtree sizes and heavy child, processed in reverse BFS order so
       every child is finalized before its parent. */
    int *size = (int*)malloc(n * sizeof(int));
    int *heavy = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { size[i] = 1; heavy[i] = -1; }
    for (int i = n - 1; i >= 1; i--) {
        int node = order[i];
        int p = parent[node];
        size[p] += size[node];
        if (heavy[p] == -1 || size[node] > size[heavy[p]]) heavy[p] = node;
    }

    /* Decompose into chains: heavy child keeps the parent's chain head,
       light children start new chains. Push heavy child last so it is
       processed immediately, keeping each chain's positions contiguous. */
    int *head = (int*)malloc(n * sizeof(int));
    int *pos = (int*)malloc(n * sizeof(int));
    int *stackNode = (int*)malloc(n * sizeof(int));
    int *stackHead = (int*)malloc(n * sizeof(int));
    int sp = 0;
    stackNode[sp] = 0; stackHead[sp] = 0; sp++;
    int curPos = 0;
    while (sp > 0) {
        sp--;
        int node = stackNode[sp];
        int h = stackHead[sp];
        head[node] = h;
        pos[node] = curPos++;
        for (int e = adjHead[node]; e < adjHead[node + 1]; e++) {
            int v = adjList[e];
            if (v != parent[node] && v != heavy[node]) {
                stackNode[sp] = v; stackHead[sp] = v; sp++;
            }
        }
        if (heavy[node] != -1) {
            stackNode[sp] = heavy[node]; stackHead[sp] = h; sp++;
        }
    }
    free(stackNode);
    free(stackHead);
    free(adjHead);
    free(adjList);
    free(order);
    free(size);
    free(heavy);

    /* Segment tree over pos[] storing a 26-bit char-parity mask per node */
    int segSize = 1;
    while (segSize < n) segSize <<= 1;
    int *seg = (int*)malloc(2 * segSize * sizeof(int));
    int *maskArr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) maskArr[pos[i]] = 1 << (s[i] - 'a');
    segBuild(seg, segSize, maskArr, n);
    free(maskArr);

    bool *answer = (bool*)malloc(queriesSize * sizeof(bool));
    int ansCount = 0;

    for (int i = 0; i < queriesSize; i++) {
        char *qstr = queries[i];
        int u, v;
        char ch;
        if (sscanf(qstr, "update %d %c", &u, &ch) == 2) {
            s[u] = ch;
            segUpdate(seg, segSize, pos[u], 1 << (ch - 'a'));
        } else if (sscanf(qstr, "query %d %d", &u, &v) == 2) {
            int res = 0;
            int uu = u, vv = v;
            while (head[uu] != head[vv]) {
                if (depth[head[uu]] < depth[head[vv]]) {
                    int tmp = uu; uu = vv; vv = tmp;
                }
                res ^= segQuery(seg, segSize, pos[head[uu]], pos[uu]);
                uu = parent[head[uu]];
            }
            if (depth[uu] > depth[vv]) {
                int tmp = uu; uu = vv; vv = tmp;
            }
            res ^= segQuery(seg, segSize, pos[uu], pos[vv]);
            answer[ansCount++] = (__builtin_popcount(res) <= 1);
        }
    }

    free(parent);
    free(depth);
    free(head);
    free(pos);
    free(seg);

    *returnSize = ansCount;
    return answer;
}
