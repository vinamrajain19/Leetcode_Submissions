/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * s= head;
        ListNode * f = head;
        
        int x = 0;
        while(f and f->next){
           
            s = s->next;
            f = f->next->next;
            if(f == s){
                x = 1;
                break;
            }
        }
        if(x == 0) return NULL;
        
        s = head;
        
        while(s and f){
            if(s == f) return s;
            s = s->next;
            f = f->next;
        }
        
        return NULL;
    }
};