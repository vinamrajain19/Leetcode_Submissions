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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL  or head->next == NULL) return head;
        int len = 1;
        ListNode * t = head;
        while(t->next != NULL){
            len++;
            t = t -> next;
        }
        t -> next = head;  // to make list as circular 1 -> 2 -> 3-> 4->5 -> 1
        
        k %= len;
        ListNode * temp = head;
        int y = len - k;
        
        while(y != 1){
            temp = temp->next;
            y--;
            
        }
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};