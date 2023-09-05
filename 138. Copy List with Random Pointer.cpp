/*
Link: https://leetcode.com/problems/copy-list-with-random-pointer/
Problem: 138. Copy List with Random Pointer
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node d = Node(0, nullptr), *t, *n, *p = nullptr;
        unordered_map<Node *, Node *> m;
        
        t = head;
        while (t){
            n = new Node(t->val, nullptr);
            if (d.next == nullptr){
                d.next = n;
            }
            
            if (p){
                p->next = n;
            }
            
            m[t] = n;
            p = n;
            t = t->next;
        }
        
        t = head;
        n = d.next;
        
        while (t && n){
            n->random = m[t->random];
            t = t->next;
            n = n->next;
        }
        
        return d.next;
        
    }
};