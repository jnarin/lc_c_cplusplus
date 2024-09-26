/*
Probblem: 729. My Calendar I
Link: https://leetcode.com/problems/my-calendar-i/
*/

typedef struct {
    int key;
    int value;
    struct MyCalendarNode *next;
} MyCalendarNode;

typedef struct {
    MyCalendarNode *head;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar *obj = calloc(1, sizeof(MyCalendar));
    obj->head = NULL;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    MyCalendarNode *node = obj->head;
    MyCalendarNode *prev = NULL;
    
    while (node) {
        if (start < node->value && end > node->key) {
            return false;
        }
        
        if (start >= node->value) {
            prev = node;
            node = node->next;
        } else {
            break;
        }
    }
    
    MyCalendarNode *newNode = calloc(1, sizeof(MyCalendarNode));
    newNode->key = start;
    newNode->value = end;
    
    if (prev) {
        newNode->next = prev->next;
        prev->next = newNode;
    } else {
        newNode->next = obj->head;
        obj->head = newNode;
    }
    
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    MyCalendarNode *node = obj->head;
    while (node) {
        MyCalendarNode *temp = node;
        node = node->next;
        free(temp);
    }
    free(obj);
}


/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
