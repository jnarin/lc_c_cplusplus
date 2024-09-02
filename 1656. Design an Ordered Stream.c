/*
Problem: 1656. Design an Ordered Stream
Link:https://leetcode.com/problems/design-an-ordered-stream/
*/




typedef struct {
    int idx;
    int size;
    int cap;
    char **values;
} OrderedStream;


OrderedStream* orderedStreamCreate(int n) {
    OrderedStream *obj = malloc(sizeof(OrderedStream));
    obj->idx = obj->size = 0;
    obj->cap = n;
    obj->values = malloc(n * sizeof(char *));
    
    int i;
    for (i = 0; i < n; i++) {
        obj->values[i] = calloc(6, sizeof(char));
    }
 
    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize) {
    idKey--;
    
    strncpy(obj->values[idKey], value, 5);
    obj->size += 1;
    
    if (idKey > obj->idx) {
        return NULL;
    }
    
    while (obj->idx < obj->size && obj->values[obj->idx][0] != '\0') {
        obj->idx++;
    }
    
    char **ans;
    int n = obj->idx - idKey, i, idx = 0;
    ans = calloc(n, sizeof(char *));
    
    for (i = idKey; i < obj->idx; i++) {
        ans[idx] = calloc(6, sizeof(char));
        strncpy(ans[idx++], obj->values[i], 5);
    }
    
    *retSize = n;
    return ans;
}

void orderedStreamFree(OrderedStream* obj) {
    int i;
    
    for (i = 0; i < obj->cap; i++) {
        free(obj->values[i]);
    }
    
    free(obj->values);
    free(obj);
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char** param_1 = orderedStreamInsert(obj, idKey, value, retSize);
 
 * orderedStreamFree(obj);
*/
