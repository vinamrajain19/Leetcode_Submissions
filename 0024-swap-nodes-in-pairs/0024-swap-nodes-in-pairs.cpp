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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL or head -> next == NULL) return head;
        
        ListNode * n = new ListNode(-1);
        ListNode * prev =  n;
        ListNode * curr = head;
        
        while(curr and curr -> next){
            
            ListNode * t = curr->next->next;
            
            prev->next = curr->next;
            prev = prev -> next;
            prev->next = curr;
            curr->next = t;
            curr = curr -> next;
            prev = prev -> next;
            
        }
        
        return n->next;
    }
};