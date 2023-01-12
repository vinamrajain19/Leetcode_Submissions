//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node * r(Node * head){
        Node * prev = NULL;
        Node * curr= head;
        Node * n = NULL;
        
        while(curr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if(head == NULL or head -> next == NULL) return true;
        Node * s = head;
        Node * f = head;
        
        while(f->next and f -> next->next){
            s = s -> next;
            f = f -> next->next;
        }
        
        Node * h2 = r(s->next);
        s -> next = NULL;
        
        Node * h1 = head;
        
        while(h1 and h2){
            if(h1 -> data != h2 -> data) return false;
            h1=h1->next;
            h2= h2->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends