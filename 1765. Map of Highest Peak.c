/*
Problem: 1765. Map of Highest Peak
Link: https://leetcode.com/problems/map-of-highest-peak/
*/

// Define the structure for a queue node
typedef struct QueueNode {
    int data[2];
    struct QueueNode* next;
} QueueNode;

// Define the structure for the queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create a new queue node
QueueNode* createNode(int *data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }

    memcpy(newNode->data, data, sizeof(int) * 2);
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    if (!queue) {
        printf("Memory allocation error\n");
        exit(1);
    }

    queue->front = queue->rear = NULL;
    return queue;
}

// Function to push an element to the queue
void push(Queue* queue, int *data) {
    QueueNode* newNode = createNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to pop an element from the queue
int pop(Queue* queue, int *data) {
    if (queue->front == NULL) {
        assert(0);
        return -1;
    }

    QueueNode* temp = queue->front;
    memcpy(data, temp->data, sizeof(int) * 2);
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Function to free the queue
void freeQueue(Queue* queue) {
    int data[2];

    while (!isEmpty(queue)) {
        pop(queue, data);
    }
    
    free(queue);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, m = isWaterSize, n = isWaterColSize[0], i, j, **ans;
    Queue* q = createQueue();

    
    ans = calloc(m, sizeof(int *));
    *returnSize = m;
    *returnColumnSizes = calloc(m, sizeof(int));
    for (i = 0; i < m; i++) {
        ans[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (isWater[i][j]) {
                push(q, (int[]){i, j});
                ans[i][j] = 0;
            } else {
                ans[i][j] = -1;
            }
        }
    }
    
    while (!isEmpty(q)) {
        int data[2];
        pop(q, data);
        for (i = 0; i < 4; i++) {
            int x = data[0] + dirs[i][0], y = data[1] + dirs[i][1];
            if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                ans[x][y] = ans[data[0]][data[1]] + 1;
                push(q, (int[]){x, y});
            }
        }
    }

    freeQueue(q);

    return ans;
}
