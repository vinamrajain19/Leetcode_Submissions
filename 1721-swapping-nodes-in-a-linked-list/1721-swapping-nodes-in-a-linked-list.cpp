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
    ListNode* swapNodes(ListNode* head, int k) {
       
        int cnt = 0;
        
        ListNode * t = head;
        ListNode * f = NULL;
        ListNode * e = NULL;
        
        while(t){
            if(cnt == k-1) f = t;
            t = t -> next;
            cnt++;
        }
        
        int x = 0;
        t = head;
        while(t and x < cnt-k){
            t = t -> next;
            x++;
        }
        e = t;
        swap(f->val,e->val);
        return head;
        
    }
};