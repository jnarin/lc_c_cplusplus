/*
Link: https://leetcode.com/problems/merge-k-sorted-lists/
Problem: 23. Merge k Sorted Lists
Approach:
Iterate through array of lists
Identify the smallest element
Change it's next pointer to the next smallest element
Increment pointer to next node of the list
Loop till there are no more lists to iterate through
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define k   (listsSize)

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i, listNum  = -1, emptyListNum, start;
    struct ListNode *c, *p, d = {0, NULL};
    
    if (k == 0){
        return NULL;
    }
    
    if (k == 1){
        return lists[0];
    }
    
    start = 0;
    while (1){
        c = lists[start];
        if (c == NULL){
            start++;
            if (start >= k){
                break;
            }
            
            continue;
        }
        
        listNum = start;
        for (i = start + 1; i < k && c; i++){
            struct ListNode *t = lists[i];
            if (t && t->val < c->val){
                c = t;
                listNum = i;
            }
        }
        
        if (d.next == NULL){
            d.next = c;
        } else {
            p->next = c;
        }
        
        p = c;
        
        lists[listNum] = lists[listNum]-> next;
        
        emptyListNum = 0;
        for (i = 0; i < k; i++){
            if (lists[i] == NULL){
                emptyListNum++;
            }
        }
        
        if (emptyListNum == k){
            break;
        }
    }
    
    if (c){
        c->next = NULL;
    }
    
    return d.next;

}
