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
    ListNode * h = NULL;
    int len = 0;
    
    Solution(ListNode* head) {
        h = head;
        ListNode * x = h;
        
        while(x){
            len++;
            x = x -> next;
        }
    }
    
    int getRandom() {
        int x = rand() % len;
        ListNode * t = h;
        int ans = 0;
        while(x--){
            t = t -> next;
        }
        return t -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */