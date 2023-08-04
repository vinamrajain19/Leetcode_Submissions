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
 
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(k<=1 || head == NULL || head->next == NULL) return head;
        
        
        ListNode *t = head;
        for(int i=0;i<k;i++)
        {
            if(t==NULL)
                return head;
            t = t->next;
        }
        
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * next = NULL;
        
        int i = 0;
        
        while(i<k and curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        
        if(next){
            head->next = reverseKGroup(next,k);
        }
        
        return prev;
        
    }
};