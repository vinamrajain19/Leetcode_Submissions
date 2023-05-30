/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * d1 = new ListNode(-1);
        ListNode * d2 = new ListNode(-1);
        
        ListNode * t1 = d1;
        ListNode * t2 = d2;
        ListNode * t = head;
        
        while(t){
            if(t->val < x){
                t1->next = t;
                t1 = t1 -> next;
            }
            else{
                t2 -> next = t;
                t2 = t2 -> next;
            }
            
            t = t -> next;
        }
        
        t2->next = NULL;
        t1->next = d2->next;
        
        return d1->next;
    }
};