/*
Link: https://leetcode.com/problems/implement-queue-using-stacks/
Problem: 232. Implement Queue using Stacks
*/

#define MAX_QUEUE_SIZE  (100 + 1)

typedef struct {
    int s1[MAX_QUEUE_SIZE], s1_size;
    int s2[MAX_QUEUE_SIZE], s2_size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = calloc(1, sizeof(MyQueue));
    obj->s1_size = obj->s2_size = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[obj->s1_size] = x;
    obj->s1_size += 1;
}

int myQueuePop(MyQueue* obj) {
    int t = myQueuePeek(obj);

    obj->s2_size -= 1;

    return t;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->s2_size == 0){
        while (obj->s1_size > 0){
            obj->s1_size -= 1;
            obj->s2[obj->s2_size] = obj->s1[obj->s1_size];
            obj->s2_size += 1;
        }
    }

    return obj->s2[obj->s2_size - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->s1_size == 0) && (obj->s2_size == 0);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/