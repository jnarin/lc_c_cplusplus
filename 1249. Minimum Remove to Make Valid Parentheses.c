/*
 * Problem: 1249. Minimum Remove to Make Valid Parentheses
 * Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * */

typedef struct LIST{
    char val;
    struct LIST *next;
}list_t;

void push(char c, list_t **head, int *size){
    list_t *node = calloc(1, sizeof(list_t));
    assert(node);
    assert(head);
    assert(size);

    node->val = c;
    node->next = NULL;

    if (*head == NULL){
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }

    *size = *size + 1;
    return;
}

void pop(list_t **head, int *size){
    list_t *node;
    assert(head);
    assert(size);

    if (*head != NULL){
        node = *head;
        *head = (*head)->next;
        free(node);
        *size = *size - 1;
    }

    return;
}

int top(char *val, list_t *head){
    int r = -1;
    assert(head);

    if (head){
        *val = head->val;
        r = 0;
    }

    return r;
}

char * minRemoveToMakeValid(char * s){
    char *t, *r;
    int len;
    list_t *head = NULL;
    int list_size = 0;
    int i, j = 0;

    assert(s);

    len = strlen(s);
    t = calloc(1, len + 1);
    assert(t);

    strcpy(t, s);

    for (i = 0; i < len; i++){
        if (t[i] == ')'){
            //printf("t[%d] == )\n", i);

            char x;
            if (list_size){
                //printf("Stack not empty\n");
                if (0 == top(&x, head) && x == '('){
                    //printf("Pop stack\n");
                    pop(&head, &list_size);
                    continue;
                }
            }
            t[i] = -1;
        } else if (t[i] == '('){
            //printf("t[%d] == (, push\n", i);
            push(t[i], &head, &list_size);
        }
    }

    for (i = len - 1; i >= 0; i--){
        if (t[i] == -1) continue;
        if (t[i] == '('){
            //printf("t[%d] == (\n", i);
            char x;
            if (list_size){
                //printf("Stack not empty\n");
                if (0 == top(&x, head) && x == ')'){
                    //printf("Pop stack\n");
                    pop(&head, &list_size);
                    continue;
                }
            }
            t[i] = -1;
        } else if (t[i] == ')'){
            //printf("t[%d] == ), push\n", i);
            push(t[i], &head, &list_size);
        }
    }

    r = calloc(1, len + 1);
    assert(r);

    for (i = 0; i < len; i++){
        if (t[i] == -1) continue;
        r[j] = t[i];
        j++;
    }

    free(t);

    return r;
}

