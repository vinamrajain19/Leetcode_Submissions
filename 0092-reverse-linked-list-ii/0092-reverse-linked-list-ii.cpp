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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        
        //skip left-1 nodes
        for(int i=0;i<left-1 and curr != NULL;i++){
            prev = curr;
            curr = curr->next;
        }
        
        ListNode * first = prev;
        ListNode * newend = curr;
        
        
        //reverse r -l + 1 nodes
        ListNode * n = curr;
        for(int i=0;i<right-left+1;i++){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        if(first != NULL){
            first->next = prev;
        }else{
            head = prev;
        }
        
        newend->next = curr;
        
        return head;
    }
};