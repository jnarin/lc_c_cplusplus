/*
 * Problem: 143. Reorder List
 * Link: https://leetcode.com/problems/reorder-list/
 * */

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

void list2Array(int *array, struct ListNode *node) {
    int i = 0;

    while (node) {
        array[i++] = node->val;
        node = node->next;
    }

    return;
}

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    int n = countNodes(head);
    int array[n];

    list2Array(array, head);

    int l = 0, r = n - 1;
    struct ListNode *node = head;

    while (l <= r) {
        if (node) {
            node->val = array[l++];
            node = node->next;
        }

        if (node) {
            node->val = array[r--];
            node = node->next;
        }
    }

    return;
}
