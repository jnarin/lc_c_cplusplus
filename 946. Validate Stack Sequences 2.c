/*
Link: https://leetcode.com/problems/validate-stack-sequences/
Problem: 946. Validate Stack Sequences 2
*/

typedef struct LIST{
    int val;
    struct LIST *next;
}list_t;

void push(list_t **head, int *size, int c){
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

int top(list_t *head, int *val){
    int r = -1;
    assert(head);
    
    if (head){
        *val = head->val;
        r = 0;
    }
    
    return r;
}


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    list_t *stack;
    int stack_size = 0;
    int i, j;
    
    assert(pushed);
    assert(popped);
    assert(pushedSize != 0);
    assert(poppedSize != 0);
    
    i = j = 0;
    
    while (i < pushedSize && j < poppedSize){
        if (stack_size){
            int x;
            int r = top(stack, &x);
            if (0 == r && x == popped[j]){
                pop(&stack, &stack_size);
                j++;
                continue;
            }
        }
        
        push(&stack, &stack_size, pushed[i]);
        i++;
    }
    
    if (i >= pushedSize){
        while (j < poppedSize){
            if (stack_size){
                int x;
                int r = top(stack, &x);
                if (0 == r && x == popped[j]){
                    pop(&stack, &stack_size);
                    j++;
                    continue;
                } else {
                    break;
                }
            }
        }
    }
    return (i == j && stack_size == 0);
}