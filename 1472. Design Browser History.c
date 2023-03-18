/*
Link: https://leetcode.com/problems/design-browser-history/
Problem: 1472. Design Browser History
Approach:
Use an array to store the URLs
Navigate through the array as required based
Handle corner cases for steps for both forward and back navigation
*/

#define MAX_URL_LEN (20)
#define MAX_DEPTH   (500)
#define DEBUG 0
#define dprint(fmt, ...) do { if (DEBUG) printf("%s:%d:%s(): " fmt, __FILE__, \
                                __LINE__, __func__, __VA_ARGS__); } while (0)

typedef struct {
    char url[MAX_DEPTH][MAX_URL_LEN + 1];
    int curr, max;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char * homepage) {
    assert(homepage);
    assert(homepage[0]);
    BrowserHistory *obj = calloc(1, sizeof(BrowserHistory));
    assert(obj);
    
    strncpy(obj->url[obj->curr], homepage, MAX_URL_LEN);
    
    obj->curr = obj->max = 1;
    dprint("max %d curr %d url %s\n", obj->max, obj->curr, obj->url[obj->curr - 1]);
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
    assert(obj);
    assert(url);
    assert(url[0]);
    
    strncpy(obj->url[obj->curr], url, MAX_URL_LEN);

    obj->curr += 1;
    obj->max = obj->curr;
    dprint("max %d curr %d url %s\n", obj->max, obj->curr, obj->url[obj->curr - 1]);
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
    assert(obj);
    while (steps > 0){
        steps--;
        obj->curr -= 1;
    }
    
    obj->curr = obj->curr < 1 ? 1 : obj->curr;
    dprint("max %d curr %d url %s\n", obj->max, obj->curr, obj->url[obj->curr - 1]);
    
    return obj->url[obj->curr - 1];
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
    assert(obj);
    while (steps > 0){
        steps--;
        obj->curr += 1;
    }
    
    obj->curr = obj->curr > obj->max ? obj->max : obj->curr;
    dprint("max %d curr %d url %s\n", obj->max, obj->curr, obj->url[obj->curr - 1]);

    return obj->url[obj->curr - 1];
}

void browserHistoryFree(BrowserHistory* obj) {
    assert(obj);
    
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char * param_2 = browserHistoryBack(obj, steps);
 
 * char * param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/
