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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        
        for(int i = 0;i<lists.size();i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        
        ListNode * head = new ListNode(0);
        ListNode * temp = head;
        
        while(pq.size()){
            auto it = pq.top();
            pq.pop();
            
            temp -> next = it.second;
            temp = it.second;
            
            if(it.second->next != NULL){
                pq.push({it.second->next->val,it.second->next});
            }
        }
        
        temp -> next = NULL;
        return head -> next;
        
    }
};