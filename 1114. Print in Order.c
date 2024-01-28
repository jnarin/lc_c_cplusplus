/*
 * Link: https://leetcode.com/problems/print-in-order/
 * Problem: 1114. Print in Order
 * */

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t thread1Complete, thread2Complete;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));

    // Initialize user defined data here.
    pthread_mutex_init(&obj->thread1Complete, NULL);
    pthread_mutex_init(&obj->thread2Complete, NULL);

    pthread_mutex_lock(&obj->thread1Complete);
    pthread_mutex_lock(&obj->thread2Complete);

    return obj;
}

void first(Foo* obj) {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();

    pthread_mutex_unlock(&obj->thread1Complete);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->thread1Complete);

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();

    pthread_mutex_unlock(&obj->thread2Complete);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->thread2Complete);

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->thread1Complete);
    pthread_mutex_destroy(&obj->thread2Complete);
    free(obj);

}

