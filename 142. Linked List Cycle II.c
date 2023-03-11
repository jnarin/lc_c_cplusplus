/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *a, *b;
    a = b = head;
    while (a && a->next && b){
        a = a->next->next;
        b = b->next;
        if (a == b){
            b = head;
            while (a != b){
                a = a->next;
                b = b->next;
            }
            
            return b;
        }
    }
    return NULL;
}

