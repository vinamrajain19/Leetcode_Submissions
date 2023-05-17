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
    
    ListNode * r(ListNode * head){
        ListNode * p = NULL;
        ListNode * c = head;
        ListNode * n = NULL;
        
        while(c){
            n = c->next;
            c -> next = p;
            p = c;
            c = n;
        }
        
        return p;
    }
    
    int pairSum(ListNode* head) {
        int ans = -1e9;
        
        ListNode * s = head;
        ListNode * f = head;
        
        while(f and f->next){
            s = s -> next;
            f = f -> next -> next;
        }
        
        ListNode * t = r(s);
        
        ListNode * h1 = head;
        ListNode * h2 = t;
        
        while(h2){
            ans = max(ans,h1->val+h2->val);
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        
        return ans;
        
        
        
    }
};