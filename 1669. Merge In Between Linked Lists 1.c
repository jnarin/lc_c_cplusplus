/*
Link: https://leetcode.com/problems/merge-in-between-linked-lists/
Problem: 1669. Merge In Between Linked Lists
Approach 1: Convert both lists to into array 
Create new array with the mentioned constraints
Convert new array into list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int countNodes(struct ListNode *list) {
    int c = 0;
    
    while (list) {
        c++;
        list = list->next;
    }
    
    return c;
}

static void list2Array(struct ListNode *list, int *array) {
    int i = 0;
    
    while (list) {
        array[i++] = list->val;
        list = list->next;
    }
    
    return;
}

static struct ListNode *array2List(int *array, int size) {
    if (size < 1) {
        return NULL;
    }
    
    struct ListNode *head = calloc(1, sizeof(struct ListNode)), *p;
    head->val = array[0];
    head->next = NULL;
    
    p = head;
    
    int i;
    
    for (i = 1; i < size; i++) {
        struct ListNode *node = calloc(1, sizeof(struct ListNode));
        node->val = array[i];
        node->next = NULL;
        
        p->next = node;
        p = node;
    }
    
    return head;
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int size1 = countNodes(list1), size2 = countNodes(list2);
    int array1[size1], array2[size2], ansArray[size1 + size2], idx = 0;
    
    list2Array(list1, array1);
    list2Array(list2, array2);
    memset(ansArray, 0, sizeof(ansArray));
    
    memcpy(&ansArray[idx], &array1[0], a * sizeof(int));
    idx += a;
    memcpy(&ansArray[idx], &array2[0], size2 * sizeof(int));
    idx += size2;
    memcpy(&ansArray[idx], &array1[b + 1], (size1 - b - 1) * sizeof(int));
    idx += size1 - b - 1;
    
    return array2List(ansArray, idx);
}