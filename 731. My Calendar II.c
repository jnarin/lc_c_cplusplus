/*
Problem: 731. My Calendar II
Link: https://leetcode.com/problems/my-calendar-ii/
*/

struct pair {
    int start;
    int end;
    struct pair *next;
};


typedef struct {
    struct pair *calendar;
    int calendarSize;
    struct pair *overlaps;
    int overlapsSize;
} MyCalendarTwo;


MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo *obj = calloc(1, sizeof(MyCalendarTwo));
    obj->calendar = NULL;
    obj->calendarSize = 0;
    
    obj->overlaps = NULL;
    obj->overlapsSize = 0;

    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    struct pair *calendarNode = obj->calendar, *overlapsNode = obj->overlaps, *newNode;

    while(calendarNode) {
        if((start >= calendarNode->start && start < calendarNode->end) 
                || (end > calendarNode->start && end <= calendarNode->end) 
                || (start <= calendarNode->start && end >= calendarNode->end)) {
            while(overlapsNode) {
                if((start >= overlapsNode->start && start < overlapsNode->end)
                || (end > overlapsNode->start && end <= overlapsNode->end) 
                || (start <= overlapsNode->start && end >= overlapsNode->end)) {
                    return false;
                }

                overlapsNode = overlapsNode->next;
            }

            newNode = calloc(1, sizeof(struct pair));

            newNode->start = start > calendarNode->start ? start : calendarNode->start;
            newNode->end = end < calendarNode->end ? end : calendarNode->end;
            newNode->next = obj->overlaps;

            obj->overlaps = newNode;
        }

        calendarNode = calendarNode->next;
    }

    newNode = calloc(1, sizeof(struct pair));
    
    newNode->start = start;
    newNode->end = end;
    newNode->next = obj->calendar;
    obj->calendar = newNode;

    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    struct pair *node = obj->calendar, *curr;

    node = obj->calendar;
    while(node) {
        curr = node;
        node = node->next;
        free(curr);
    }

    node = obj->overlaps;
    while(node) {
        curr = node;
        node = node->next;
        free(curr);
    }

    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/
