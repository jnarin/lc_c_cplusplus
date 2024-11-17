/*
Problem: 862. Shortest Subarray with Sum at Least K
Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

static Node *createNode(int data) {
    Node *newNode = calloc(1, sizeof(Node));
    assert(newNode);

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

static Deque *createDeque() {
    Deque *deque = calloc(1, sizeof(Deque));
    assert(deque);
    
    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}

static int isEmpty(Deque *deque) {
    return (deque->front == NULL);
}

static void pushFront(Deque *deque, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

static void pushRear(Deque *deque, int data) {
    Node *newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

static int popFront(Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    }
    
    Node *temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    
    if (deque->front) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }

    free(temp);

    return data;
}

static int popRear(Deque *deque) {
    if (isEmpty(deque)) {
        return -1;
    }
    
    Node *temp = deque->rear;
    int data = temp->data;
    deque->rear = deque->rear->prev;
    
    if (deque->rear){
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }

    free(temp);

    return data;
}

static void freeDeque(Deque *deque) {
    while (!isEmpty(deque)) {
        popFront(deque);
    }

    free(deque);
}

int shortestSubarray(int* nums, int numsSize, int k) {
    long sum[numsSize + 1];
    int i;

    sum[0] = 0;
    for (i = 0; i < numsSize; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
    
    Deque *q = createDeque();
    int ans = numsSize + 1;

    for (i = 0; i <= numsSize; i++) {
        while(!isEmpty(q) && sum[i] - sum[q->front->data] >= k) {
            ans = MINVAL(ans, i - q->front->data);
            popFront(q);
        }

        while (!isEmpty(q) && sum[q->rear->data] >= sum[i]) {
            popRear(q);
        }

        pushRear(q, i);
    }

    freeDeque(q);
    
    return ans > numsSize ? -1 : ans;
}

