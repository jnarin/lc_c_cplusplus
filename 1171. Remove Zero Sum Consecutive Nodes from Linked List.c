/*
Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
Problem: 1171. Remove Zero Sum Consecutive Nodes from Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int countNodes(struct ListNode *node) {
    int c = 0;
    
    while (node) {
        node = node->next;
        c++;
    }
    
    return c;
}


static void copyListToArray(int *array, struct ListNode *node) {
    int i = 0;
    
    while (node) {
        array[i++] = node->val;
        node = node->next;
    }
    
    return;
}

static int getZeroSumIdx(int *array, int arraySize, int idx) {
    int sum = 0;
    
    while (idx < arraySize) {
        if (array[idx] != INT_MIN) {
            sum += array[idx];

            if (sum == 0) {
                return idx;
            }
        }
        
        idx++;
    }
    
    return -1;
}


struct ListNode *copyArrayToList(int *array, int arraySize) {
    struct ListNode *head = NULL, *p = NULL, *node;
    
    int i;
    
    for (i = 0; i < arraySize; i++) {
        if (array[i] != INT_MIN) {
            if (head == NULL) {
                head = calloc(1, sizeof(struct ListNode));
                head->val = array[i];
                head->next = NULL;
                
                p = head;
            } else {
                node = calloc(1, sizeof(struct ListNode));
                node->val = array[i];
                node->next = NULL;
                
                p->next = node;
                p = node;
            }
        }
    }
    
    return head;
} 

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    int nodeCount = countNodes(head);
    
    int array[nodeCount];
    memset(array, 0, sizeof(array));
    
    copyListToArray(array, head);
    
    int i;
    
    for (i = 0; i < nodeCount; i++) {
        int t = getZeroSumIdx(array, nodeCount, i);
        if (t != -1) {
            int j = i;
            while (j <= t) {
                array[j++] = INT_MIN;
            }
        }
    }
    
    return copyArrayToList(array, nodeCount);
}