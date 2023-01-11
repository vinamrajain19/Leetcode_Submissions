//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
 
    
    Node* r(struct Node *head)
    {
        // code here
        // return head of reversed list
        
        Node * prev = NULL;
        Node * curr = head;
        Node * next = NULL;
        
        while(curr){
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }
        
        return prev;
        
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        Node * l1 = r(first);
        Node * l2 = r(second);
        
        Node * n = new Node(0);
        Node * temp = n;
        
        int carry = 0;
        
        while(l1 or l2 or carry){
            int sum = 0;
            if(l1){
                sum += l1->data;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2->data;
                l2 = l2 -> next;
            }
            
            sum += carry;
            carry = (sum >= 10) ? 1 : 0;
            sum %= 10;
            Node * x = new Node(sum);
            temp -> next = x;
            temp = temp -> next;
        }
        
        Node * ans = r(n->next);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends